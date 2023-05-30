#include "Headers/Portfolio.h"
#include "Headers/Matrix.h"
#include<iostream>

Portfolio::Portfolio(const Matrix& assetReturns)
    : assetReturns(assetReturns) {}

void Portfolio::addAssetReturnsIndex(int start, int end) {
    assetReturnsIndexes[0] = start;
    assetReturnsIndexes[1] = end;
}

void Portfolio::calculateMeanReturns() {
    Matrix portfolioAssets = assetReturns.subset(assetReturnsIndexes[0], assetReturnsIndexes[1]);
   
    portfolioAssets.transposeInPlace();
    int numAssets = portfolioAssets.getData().size();
    std::cout << "Num Assets:" << numAssets << std::endl;
    int numDays = portfolioAssets.getData()[0].size();
     std::cout << "Num Days:" << numDays << std::endl;

    meanReturns.clear();

    for (int i = 0; i < numAssets; ++i) {
        double sum = 0.0;
        for (int k = 0; k < numDays; ++k) {
            sum += portfolioAssets.getData()[i][k];
        }
        double meanReturn = sum / numDays;
        meanReturns.push_back(meanReturn);
    }
}

void Portfolio::calculateCovarianceMatrix() {
    Matrix portfolioAssets = assetReturns.subset(assetReturnsIndexes[0], assetReturnsIndexes[1]);
    portfolioAssets.transposeInPlace();
    int numAssets = portfolioAssets.getData().size();
    int numDays = portfolioAssets.getData()[0].size();

    //calculateMeanReturns();

    covarianceMatrix = Matrix(numAssets, numAssets);

    for (int i = 0; i < numAssets; ++i) {
        for (int j = 0; j <= i; ++j) {
            double sum = 0.0;
            for (int k = 0; k < numDays; ++k) {
                double diff_i = portfolioAssets.getData()[i][k] - meanReturns[i];
                double diff_j = portfolioAssets.getData()[j][k] - meanReturns[j];
                sum += diff_i * diff_j;
            }
            double cov = sum / (numDays - 1);
            covarianceMatrix.setData(i, j, cov);
            covarianceMatrix.setData(j, i, cov); // Covariance matrix is symmetric
        }
    }
}

std::vector<double> Portfolio::getMeanReturns() {
    if (meanReturns.empty()) {
        calculateMeanReturns();
    }
    return meanReturns;
}

Matrix Portfolio::getCovarianceMatrix() {
    if (covarianceMatrix.getData().empty()) {
        calculateCovarianceMatrix();
    }
    return covarianceMatrix;
}
