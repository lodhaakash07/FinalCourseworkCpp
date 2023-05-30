#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Asset.h"
#include "Matrix.h"
#include <vector>

class Portfolio {
private:
    std::vector<Asset> assets;
    std::vector<double> weights;
    std::vector<double> meanReturns;
    Matrix covarianceMatrix;

public:
    Portfolio();

    void addAsset(const Asset& asset);
    void addWeight(double weight);

    std::vector<Asset> getAssets() const;
    std::vector<double> getWeights() const;
    std::vector<double> getMeanReturns();
    Matrix getCovarianceMatrix();
};

#endif // PORTFOLIO_H
