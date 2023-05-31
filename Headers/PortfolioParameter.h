#ifndef PORTFOLIOPARAMETER_H
#define PORTFOLIOPARAMETER_H

#include "ConjugateGradientOptimiser.h"
#include "Assets.h"


class PortfolioParameter : public ConjugateGradientOptimiser {
private:
    std::vector<double> weight;

public:
    PortfolioParameter();

    std::vector<double> generateWeights(Assets& assets, double targetReturn);
    std::vector<double> getWeight();

};

#endif // PORTFOLIOPARAMETER_H
