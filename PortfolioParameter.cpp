#include "Headers/PortfolioParameter.h"

PortfolioParameter::PortfolioParameter() {
    // Constructor implementation goes here
}


std::vector<double> PortfolioParameter::generateWeights(Assets& assets, double targetReturn) {

    const Matrix& covMatrix = assets.getCovarianceMatrix();
    const std::vector<double>& meanReturns = assets.getMeanReturns();

    // Call the optimizer's getWeights function
    weight =  ConjugateGradientOptimiser::getWeights(covMatrix, meanReturns, targetReturn);
    return weight;
}


std::vector<double> PortfolioParameter::getWeight() {
    return weight;
}