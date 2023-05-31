#include "Headers/ConjugateGradientOptimiser.h"
#include "Headers/Matrix.h"

std::vector<double> ConjugateGradientOptimiser::getWeights(const Matrix& covarianceMatrix, const std::vector<double>& meanReturns, const std::vector<double>& targetReturns) {
    // Calculate the dimensions
    int numAssets = covarianceMatrix.size();
    int numConstraints = targetReturns.size() + 1;

    // Create the augmented matrix
    Matrix augmentedMatrix;
    augmentedMatrix.resize(numAssets + numConstraints);
    for (int i = 0; i < numAssets + numConstraints; ++i) {
        augmentedMatrix[i].resize(numAssets + numConstraints, 0.0);
    }

    // Populate the augmented matrix
    for (int i = 0; i < numAssets; ++i) {
        for (int j = 0; j < numAssets; ++j) {
            augmentedMatrix[i][j] = covarianceMatrix[i][j];
        }
    }

    for (int i = 0; i < numAssets; ++i) {
        augmentedMatrix[i][numAssets] = -meanReturns[i];
        augmentedMatrix[numAssets][i] = -meanReturns[i];
    }

    // Set the target returns and the additional constraint
    for (int i = 0; i < numConstraints - 1; ++i) {
        augmentedMatrix[numAssets + i][numAssets] = targetReturns[i];
    }

    augmentedMatrix[numAssets][numAssets] = 0.0;

    // Solve the system of linear equations using the conjugate gradient method
    std::vector<double> weights(numAssets, 0.0);

    std::vector<double> s = targetReturns;
    for (int i = 0; i < numAssets; ++i) {
        s[i] -= meanReturns[i];
    }

    std::vector<double> p = s;
    double epsilon = 1e-6;
    double tolerance = epsilon * Matrix().dotProduct(s, s);

    int k = 0;
    while (Matrix().dotProduct(s, s) > tolerance) {
        double alpha = Matrix::dotProduct(s, s) / Matrix().dotProduct(p, augmentedMatrix.multiplyMatrixVector(augmentedMatrix, p));

        for (int i = 0; i < numAssets; ++i) {
            weights[i] += alpha * p[i];
            s[i] -= alpha * Matrix::dotProduct(augmentedMatrix[i], p);
        }

        double beta = Matrix().dotProduct(s, s) / Matrix::dotProduct(p, p);

        for (int i = 0; i < numAssets; ++i) {
            p[i] = s[i] + beta * p[i];
        }

        ++k;
    }

    return weights;
}
