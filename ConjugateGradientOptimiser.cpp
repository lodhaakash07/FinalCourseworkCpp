#include "Headers/ConjugateGradientOptimiser.h"
#include <iostream>

std::vector<double> ConjugateGradientOptimiser::getWeights(const Matrix& covMatrix, const std::vector<double>& meanReturns, double targetReturn) {
    const double tolerance = 1e-6;

    int numAssets = meanReturns.size();
    Matrix Q;

    Q.resize(numAssets + 2, std::vector<double>(numAssets + 2, 0.0));

    // Copy covMatrix values to Q
    for (int i = 0; i < numAssets; ++i) {
        for (int j = 0; j < numAssets; ++j) {
            Q[i][j] = covMatrix[i][j];
        }
    }

    // Set the last two rows and columns of Q
    for (int i = 0; i < numAssets; ++i) {
        Q[i][numAssets] = Q[i][numAssets + 1] = meanReturns[i];
        Q[numAssets][i] = Q[numAssets + 1][i] = meanReturns[i];
    }

    // Add a small positive value to the diagonal of Q
    for (int i = 0; i < numAssets; ++i) {
        Q[i][i] += 1e-6;
    }



    std::vector<double> x(numAssets + 2, 0);
    std::vector<double> b(numAssets + 2, 0);
    b[numAssets] = -targetReturn;
    b[numAssets + 1] = -1;

    std::vector<double> s = Q.subtractVectors(b, Q.multiplyMatrixVector(Q, x));
    std::vector<double> p = s;

    for (size_t k = 0; Q.norm(s) > tolerance; k++) {
        std::vector<double> Qp = Q.multiplyMatrixVector(Q, p);

        double alpha = Q.dotProduct(s, s) / Q.dotProduct(p, Qp);

        // Check if alpha is infinity or NaN
        if (std::isinf(alpha) || std::isnan(alpha)) {
            std::cout << "Error: alpha is infinity or NaN" << std::endl;
            // Return default weights or handle the error condition as desired
            return std::vector<double>(numAssets, 0.0);
        }

        std::vector<double> QpAlpha = Q.multiplyVector(alpha, Qp);
        x = Q.addVectors(x, QpAlpha);

        s = Q.subtractVectors(s, QpAlpha);

        if (Q.norm(s) <= tolerance) {
            break;
        }

        double beta = Q.dotProduct(s, s) / Q.dotProduct(Qp, p);

        // Check if beta is NaN
        if (std::isnan(beta)) {
            std::cout << "Error: beta is NaN" << std::endl;
            // Return default weights or handle the error condition as desired
            return std::vector<double>(numAssets, 0.0);
        }

        p = Q.addVectors(s, Q.multiplyVector(beta, p));
    }

    std::vector<double> weights(x.begin(), x.begin() + numAssets);

    return weights;
}
