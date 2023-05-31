#include <iostream>
#include <vector>
#include "Headers/Matrix.h"
#include "Headers/CSVHandler.h"
#include "Headers/Window.h"
#include "Headers/Assets.h"
#include "Headers/Portfolio.h"
#include "Headers/ConjugateGradientOptimiser.h"
#include "Headers/TargetReturns.h"

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


    // Loop over assetReturns to create rolling window portfolios
    int numAssets = assetReturns.front().size();
    std::cout << "Number of assets: " << numAssets << std::endl;

    int count = 0;
    TargetReturns targetReturns;
    for (int currentIndex = 0; currentIndex + window.getInSampleSize() < assetReturns.size(); currentIndex += window.getOutSampleSize()) {

        std::cout << "Processing in-sample rolling window: " << count++ << std::endl;
        Portfolio portfolio(assetReturns);
        portfolio.addAssetReturnsIndex(currentIndex, currentIndex + window.getInSampleSize());

        // Calculate mean returns and covariance matrix
        portfolio.populateAssetsMeanCovariance();

        for (const auto& targetReturn : targetReturns.getTargetReturns()) {
             portfolio.populateWeights(targetReturn);
             portfolio.populateStatistics();

             std::cout << portfolio.getPortfolioMean() << "Ola" << portfolio.getPortfolioCovariance() << std::endl;
        } 
        std::cout << std::endl;
       
    }
    std::cout << "Success" << std::endl;

    return 0;
}
