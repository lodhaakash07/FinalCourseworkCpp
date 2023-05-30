#include <iostream>
#include <vector>
#include "Headers/Matrix.h"
#include "Headers/CSVHandler.h"

#include "Headers/Window.h"
#include <iostream>
#include <vector>
#include "Headers/Portfolio.h"
int main() {

    // Read the file
    CSVHandler csvHandler;
    Matrix assetReturns = csvHandler.readCSV("Data/asset_returns.csv");

    // Check if matrix is empty
    if (assetReturns.getData().empty()) {
        std::cout << "Matrix is empty" << std::endl;
        return 0;
    }

    // Create an object of Window
    Window window(100, 10);

    // Create an array of Portfolios
    std::vector<Portfolio> portfolios;

    // Loop over assetReturns to create rolling window portfolios
    int numAssets = assetReturns.getData()[1].size();
    std::cout << "Number of assets: " << numAssets << std::endl;

    int count = 0;
    for (int currentIndex = 0; currentIndex + window.getInSampleSize() < assetReturns.getData().size(); currentIndex += window.getOutSampleSize()) {
        
        std::cout << "Processing in sample rolling window : " << count++ << std::endl;
        Portfolio portfolio(assetReturns);
        portfolio.addAssetReturnsIndex(currentIndex, currentIndex + window.getInSampleSize());

        // Calculate mean returns and covariance matrix
        portfolio.calculateMeanReturns();
        portfolio.calculateCovarianceMatrix();

        portfolios.push_back(portfolio);
       
    }

    std::cout << "Success" << std::endl;

    return 0;
}
