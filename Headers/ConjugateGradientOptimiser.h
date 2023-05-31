#ifndef CONJUGATEGRADIENTOPTIMISER_H
#define CONJUGATEGRADIENTOPTIMISER_H

#include "PortfolioOptimiser.h"

class ConjugateGradientOptimiser : public PortfolioOptimiser {
public:
    std::vector<double> getWeights(const Matrix& covarianceMatrix, const std::vector<double>& meanReturns, const std::vector<double>& targetReturns) override;
};

#endif // CONJUGATEGRADIENTOPTIMISER_H
