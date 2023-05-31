#ifndef CONJUGATEGRADIENTOPTIMISER_H
#define CONJUGATEGRADIENTOPTIMISER_H

#include "PortfolioOptimiser.h"
#include "Matrix.h"
#include <vector>

class ConjugateGradientOptimiser : public PortfolioOptimiser {
public:
    std::vector<double> getWeights(const Matrix& covMatrix, const std::vector<double>& meanReturns, double targetReturn) override;
};

#endif // CONJUGATEGRADIENTOPTIMISER_H
