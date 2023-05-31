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

    std::vector<std::vector<double> > data;
    // Loop over assetReturns to create rolling window portfolios
    int numAssets = assetReturns.front().size();
    std::cout << "Number of assets: " << numAssets << std::endl;

    int count = 0;
    TargetReturns targetReturns;
    for (int currentIndex = 0; currentIndex + window.getInSampleSize() < assetReturns.size(); currentIndex += window.getOutSampleSize()) {

        std::cout << "Processing in-sample rolling window: " << count++ << std::endl;
        Portfolio inSamplePortfolio(assetReturns);
        Portfolio outSamplePortfolio(assetReturns);
        
        inSamplePortfolio.addAssetReturnsIndex(currentIndex, currentIndex + window.getInSampleSize());
        outSamplePortfolio.addAssetReturnsIndex(currentIndex + window.getInSampleSize(), currentIndex + window.getInSampleSize() + window.getOutSampleSize());

        // Calculate mean returns and covariance matrix
        inSamplePortfolio.populateAssetsMeanCovariance();
        outSamplePortfolio.populateAssetsMeanCovariance();

        for (const auto& targetReturn : targetReturns.getTargetReturns()) {
             inSamplePortfolio.populateWeights(targetReturn);
             inSamplePortfolio.populateStatistics();
             outSamplePortfolio.setWeight(inSamplePortfolio.getWeight());
             outSamplePortfolio.populateStatistics();
             std::cout << " (window, targetReturn) = " << count << ", " << targetReturn << std::endl;
             std::cout << "Insample (mean, covariance) = " << inSamplePortfolio.getPortfolioMean() << ", " << inSamplePortfolio.getPortfolioCovariance() << std::endl;
             std::cout << "Outsample (mean, covariance) = " << outSamplePortfolio.getPortfolioMean() << ", " << outSamplePortfolio.getPortfolioCovariance() << std::endl;
             std::cout << std::endl;

             std::vector<double> row;
            row.push_back(static_cast<double>(count));
            row.push_back(targetReturn);
            row.push_back(inSamplePortfolio.getPortfolioMean());
            row.push_back(inSamplePortfolio.getPortfolioCovariance());
            row.push_back(outSamplePortfolio.getPortfolioMean());
            row.push_back(outSamplePortfolio.getPortfolioCovariance());

            data.push_back(row);


        } 
        std::cout << std::endl;
        csvHandler.writeDataToCSV(data, "portfolio_data.csv");
    }

    return 0;
}
