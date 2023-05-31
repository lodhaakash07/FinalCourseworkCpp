#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Assets.h"
#include "PortfolioParameter.h"
#include <vector>

class Portfolio : public Assets, public PortfolioParameter {
private:
    double portfolioMean;
    double portfolioCovariance;
    void calculatePortfolioMean();
    void calculatePortfolioCovariance();

public:
    Portfolio(const Matrix& assetReturns);

    void populateWeights(double targetReturn);
    void populateStatistics();

    double getPortfolioMean() const;
    double getPortfolioCovariance() const;
};

#endif // PORTFOLIO_H
