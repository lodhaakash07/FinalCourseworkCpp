#include <iostream>
#include <vector>
#include "Headers/Matrix.h"
#include "Headers/CSVHandler.h"
#include "Headers/Window.h"
#include "Headers/Portfolio.h"
#include "Headers/ConjugateGradientOptimiser.h"

int main() {
    // Read the file
    CSVHandler csvHandler;
    Matrix assetReturns = csvHandler.readCSV("Data/asset_returns.csv");

    // Check if matrix is empty
    if (assetReturns.empty()) {
        std::cout << "Matrix is empty" << std::endl;
        return 0;
    }

    // Create an object of Window
    Window window(100, 12);

    // Create an array of Portfolios
    std::vector<Portfolio> portfolios;

    // Loop over assetReturns to create rolling window portfolios
    int numAssets = assetReturns.front().size();
    std::cout << "Number of assets: " << numAssets << std::endl;

    int count = 0;
    ConjugateGradientOptimiser optimiser;
     double targetReturn = 0.05;
    for (int currentIndex = 0; currentIndex + window.getInSampleSize() < assetReturns.size(); currentIndex += window.getOutSampleSize()) {

        std::cout << "Processing in-sample rolling window: " << count++ << std::endl;
        Portfolio portfolio(assetReturns);
        portfolio.addAssetReturnsIndex(currentIndex, currentIndex + window.getInSampleSize());

        // Calculate mean returns and covariance matrix
        portfolio.calculateMeanReturns();
        portfolio.calculateCovarianceMatrix();

        std::vector<double> weights = optimiser.getWeights(portfolio.getCovarianceMatrix(), portfolio.getMeanReturns(), targetReturn);
        // Print weights for each portfolio
        std::cout << "Portfolio weights: ";
        for (double weight : weights) {
            std::cout << weight << " ";
        }
        std::cout << std::endl;
        portfolios.push_back(portfolio);
    }


     // Set the target return to 0.05

    std::cout << "Success" << std::endl;

    return 0;
}
