#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Matrix.h"
#include <vector>

class Portfolio {
private:
    const Matrix& assetReturns;
    int assetReturnsIndexes[2];
    std::vector<double> meanReturns;
    Matrix covarianceMatrix;

public:
    Portfolio(const Matrix& assetReturns);

    void addAssetReturnsIndex(int start, int end);
    void calculateMeanReturns();
    void calculateCovarianceMatrix();

    std::vector<double> getMeanReturns();
    Matrix getCovarianceMatrix();
};

#endif // PORTFOLIO_H