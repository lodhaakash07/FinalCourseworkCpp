#ifndef PORTFOLIOOPTIMISER_H
#define PORTFOLIOOPTIMISER_H

#include "Matrix.h"
#include <vector>

class PortfolioOptimiser {
public:
    virtual std::vector<double> getWeights(const Matrix& covarianceMatrix, const std::vector<double>& meanReturns, const std::vector<double>& targetReturns) = 0;
};

#endif // PORTFOLIOOPTIMISER_H
