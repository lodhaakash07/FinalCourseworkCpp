#include "Headers/Portfolio.h"
#include<iostream>
#include<numeric>
Portfolio::Portfolio(const Matrix& assetReturns)
    :  Assets(assetReturns) {
}

void Portfolio::populateStatistics() {
    calculatePortfolioMean();
    calculatePortfolioCovariance();
}

void Portfolio::populateWeights(double targetReturn) {
    generateWeights(*this, targetReturn);
}


void Portfolio::calculatePortfolioMean() {
    const std::vector<double>& meanReturns = getMeanReturns();
    const std::vector<double>& weights = getWeight();

    // Calculate portfolio mean
    portfolioMean = std::inner_product(meanReturns.begin(), meanReturns.end(), weights.begin(), 0.0);
}

void Portfolio::calculatePortfolioCovariance() {
    // Calculate portfolio covariance
    const Matrix& covMatrix = getCovarianceMatrix();
    const std::vector<double>& weights = getWeight();
    std::vector<double> weightsTranspose(weights.size());
    
    for (size_t i = 0; i < weights.size(); ++i) {
        weightsTranspose[i] = weights[i];
    }
    
    double dotProduct = 0.0;
    for (size_t i = 0; i < weights.size(); ++i) {
        for (size_t j = 0; j < weights.size(); ++j) {
            dotProduct += weightsTranspose[i] * covMatrix[i][j] * weights[j];
        }
    }
    portfolioCovariance = dotProduct;
}




double Portfolio::getPortfolioMean() const {
    return portfolioMean;
}

double Portfolio::getPortfolioCovariance() const {
    return portfolioCovariance;
}
