#ifndef Assets_H
#define Assets_H

#include "Matrix.h"
#include <vector>

class Assets {
private:
    const Matrix& assetReturns;
    int assetReturnsIndexes[2];
    std::vector<double> meanReturns;
    Matrix covarianceMatrix;
    void calculateMeanReturns();
    void calculateCovarianceMatrix();

public:
    Assets(const Matrix& assetReturns);

    void addAssetReturnsIndex(int start, int end);
    void populateAssetsMeanCovariance();

    std::vector<double> getMeanReturns();
    Matrix getCovarianceMatrix();
};

#endif // Assets_H