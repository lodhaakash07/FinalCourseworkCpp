#include "Headers/ConjugateGradientOptimiser.h"

std::vector<double> ConjugateGradientOptimiser::getWeights(const Matrix& covMatrix, const std::vector<double>& meanReturns, double targetReturn) {
    const double tolerance = 1e-6;  // set the tolerance ε to 10e-6

    // Form the system of linear equations Qx = b from the optimization problem
    Matrix Q = covMatrix;  // Initialize Q with the covariance matrix
    Q.appendRow(meanReturns);  // Append the mean returns to Q
    Q.appendRow(std::vector<double>(covMatrix.size(), 1));  // Append the constraint that the sum of weights equals 1

    std::vector<double> x(covMatrix.size() + 2, 0);  // x is the vector of weights and Lagrange multipliers

    std::vector<double> b(covMatrix.size(), targetReturn);  // Initialize b with the target return
    b.push_back(0);  // Append zero for the constraint on the mean returns
    b.push_back(1);  // Append one for the constraint that the sum of weights equals 1

    // Step 0: Initialize s0, p0
    std::vector<double> s = Q.subtractVectors(b, Q.multiplyMatrixVector(Q, x));  // s0 = b - Q * x0
    std::vector<double> p = s;  // p0 = s0

    // Step 1: Run the loop until the norm of sk is less than or equal to the tolerance
    for (size_t k = 0; Q.norm(s) > tolerance; k++) {
        double alpha = Q.dotProduct(s, s) / Q.dotProduct(p, Q.multiplyMatrixVector(Q, p));  // αk = s⊤k sk / p⊤k Qpk

        x = Q.addVectors(x, Q.multiplyVector(alpha, p));  // xk+1 = xk + αk * pk
        std::vector<double> old_s = s;
        s = Q.subtractVectors(s, Q.multiplyVector(alpha, Q.multiplyMatrixVector(Q, p)));  // sk+1 = sk - αk * Qpk

        double beta = Q.dotProduct(s, s) / Q.dotProduct(old_s, old_s);  // βk = s⊤k+1sk+1 / s⊤k sk
        p = Q.addVectors(s, Q.multiplyVector(beta, p));  // pk+1 = sk+1 + βk * pk
    }

    return x;
}
