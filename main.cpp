#include <iostream>
#include <vector>
#include "Headers/Matrix.h"
#include "Headers/CSVHandler.h"
#include "Headers/Asset.h"
#include "Headers/Window.h"
#include <iostream>
#include <vector>
#include "Headers/Portfolio.h"

int main() {
    CSVHandler csvHandler;
    Matrix assetReturns = csvHandler.readCSV("Data/asset_returns.csv");

    // Check if matrix is empty
    if (assetReturns.getData().empty()) {
        std::cout << "Matrix is empty" << std::endl;
        return 0;
    }

    // Create an object of Window
    Window window(12, 100);

    // Create an array of Portfolios
    std::vector<Portfolio> portfolios;

    // Loop over assetReturns to create rolling window portfolios
    int numAssets = assetReturns.getData()[1].size();
    std::cout << "Number of assets" << numAssets << std::endl;
  
    for (int currentIndex = 0; currentIndex + window.getOutSampleSize() <= assetReturns.getData().size(); currentIndex += window.getInSampleSize()) {
        Portfolio portfolio;

        for (int i = 0; i < numAssets; ++i) {
            std::vector<double> outSampleReturns(assetReturns.getData()[currentIndex].begin(), assetReturns.getData()[currentIndex].begin() + window.getOutSampleSize());
            Asset asset(std::to_string(i + 1), outSampleReturns);
            portfolio.addAsset(asset);
        }

        portfolios.push_back(portfolio);
    }

    // Loop over portfolios to estimate mean returns and covariance matrix
    for (Portfolio& portfolio : portfolios) {
        std::vector<double> meanReturns = portfolio.getMeanReturns();
        Matrix covarianceMatrix = portfolio.getCovarianceMatrix();

        // Use mean returns and covariance matrix for further analysis...
    }


    std::cout << "Success" << std::endl;

    return 0;
}