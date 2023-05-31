#include "Headers/Assets.h"
#include "Headers/Matrix.h"
#include <iostream>

Assets::Assets(const Matrix& assetReturns) : assetReturns(assetReturns) {}


void Assets::addAssetReturnsIndex(int start, int end) {
    assetReturnsIndexes[0] = start;
    assetReturnsIndexes[1] = end;
}

// Lazt loading
void Assets::populateAssetsMeanCovariance() {
    calculateMeanReturns();
    calculateCovarianceMatrix();
}

void Assets::calculateMeanReturns() {
    const Matrix& assetData = assetReturns;

    int numAssets = assetData.front().size();
    int numDays = assetData.size();

    meanReturns.clear();
    meanReturns.reserve(numAssets);

    for (int i = 0; i < numAssets; ++i) {
        double sum = 0.0;
        for (int k = assetReturnsIndexes[0]; k < assetReturnsIndexes[1]; ++k) {
            sum += assetData[k][i];
        }
        double meanReturn = sum / (assetReturnsIndexes[1] - assetReturnsIndexes[0]);
        meanReturns.push_back(meanReturn);
    }
}

void Assets::calculateCovarianceMatrix() {
    const Matrix& assetData = assetReturns;

    int numAssets = assetData[0].size();
    int numDays = assetData.size();

    covarianceMatrix.clear();
    covarianceMatrix.resize(numAssets, std::vector<double>(numAssets));

    for (int i = 0; i < numAssets; ++i) {
        for (int j = 0; j < numAssets; ++j) {
            double sum = 0.0;
            for (int k = assetReturnsIndexes[0]; k < assetReturnsIndexes[1]; ++k) {
                double diff_i = assetData[k][i] - meanReturns[i];
                double diff_j = assetData[k][j] - meanReturns[j];
                sum += diff_i * diff_j;
            }
            double cov = sum / (assetReturnsIndexes[1] - assetReturnsIndexes[0]);
            covarianceMatrix[i][j] = cov;
            covarianceMatrix[j][i] = cov; // Covariance matrix is symmetric
        }
    }
}


std::vector<double> Assets::getMeanReturns() {
    if (meanReturns.empty()) {
        calculateMeanReturns();
    }
    return meanReturns
    
    ;
}

Matrix Assets::getCovarianceMatrix() {
    if (covarianceMatrix.empty()) {
        calculateCovarianceMatrix();
    }
    return covarianceMatrix;
}