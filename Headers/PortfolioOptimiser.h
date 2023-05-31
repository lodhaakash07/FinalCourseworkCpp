#ifndef PORTFOLIOOPTIMISER_H
#define PORTFOLIOOPTIMISER_H

#include "Matrix.h"
#include <vector>

class PortfolioOptimiser {
public:
    virtual std::vector<double> getWeights(const Matrix& covMatrix, const std::vector<double>& meanReturns, double targetReturn) = 0;
};

#endif // PORTFOLIOOPTIMISER_H
