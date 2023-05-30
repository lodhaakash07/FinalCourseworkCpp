#include "Headers/Portfolio.h"

Portfolio::Portfolio() {}

void Portfolio::addAsset(const Asset& asset) {
    assets.push_back(asset);
}

void Portfolio::addWeight(double weight) {
    weights.push_back(weight);
}

std::vector<Asset> Portfolio::getAssets() const {
    return assets;
}

std::vector<double> Portfolio::getWeights() const {
    return weights;
}

std::vector<double> Portfolio::getMeanReturns() {
    if (meanReturns.empty()) {
        // Calculate the mean returns
        const std::vector<Asset>& assets = getAssets();
        int numDays = assets[0].getReturns().size();
        int numAssets = assets.size();

        meanReturns.resize(numAssets);  // Resize the vector before assigning values

        for (int i = 0; i < numAssets; ++i) {
            const std::vector<double>& returns = assets[i].getReturns();
            double sum = 0.0;
            for (int k = 0; k < numDays; ++k) {
                sum += returns[k];
            }
            meanReturns[i] = sum / numDays;
        }
    }

    return meanReturns;
}

Matrix Portfolio::getCovarianceMatrix() {
    if (covarianceMatrix.getData().empty()) {
        // Calculate the mean returns
        std::vector<double> meanReturns = getMeanReturns();

        // Calculate the covariance matrix
        const std::vector<Asset>& assets = getAssets();
        int numDays = assets[0].getReturns().size();
        int numAssets = assets.size();

        covarianceMatrix = Matrix(numAssets, numAssets);

        for (int i = 0; i < numAssets; ++i) {
            const std::vector<double>& returns1 = assets[i].getReturns();
            for (int j = 0; j < numAssets; ++j) {
                const std::vector<double>& returns2 = assets[j].getReturns();
                double sum = 0.0;
                for (int k = 0; k < numDays; ++k) {
                    sum += (returns1[k] - meanReturns[i]) * (returns2[k] - meanReturns[j]);
                }
                covarianceMatrix.setData(i, j, sum / (numDays - 1));
            }
        }
    }

    return covarianceMatrix;
}
