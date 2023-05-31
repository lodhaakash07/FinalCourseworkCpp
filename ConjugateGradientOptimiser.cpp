#include "Headers/ConjugateGradientOptimiser.h"
#include "Headers/Matrix.h"

std::vector<double> ConjugateGradientOptimiser::getWeights(const Matrix& covMatrix, const std::vector<double>& meanReturns, double targetReturn) {
    // Number of assets
    size_t numAssets = covMatrix.size();

    // Initialize weights vector with equal allocation
    std::vector<double> weights(numAssets, 1.0 / numAssets);

    // Conjugate Gradient iterations
    size_t maxIterations = 1000;  // Maximum number of iterations
    double tolerance = 1e-6;     // Tolerance for convergence

    std::vector<double> gradient(numAssets);    // Gradient vector
    std::vector<double> direction(numAssets);   // Conjugate direction vector
    std::vector<double> prevDirection(numAssets);  // Previous conjugate direction vector

    double alpha, beta, dotProduct, normGradient;

    for (size_t iteration = 0; iteration < maxIterations; iteration++) {
        // Calculate gradient
        gradient = covMatrix.multiplyMatrixVector(covMatrix, weights);
        gradient = covMatrix.multiplyVector(2.0, gradient);
        std::vector<double> meanReturnsScaled = covMatrix.multiplyVector(2.0 * targetReturn, meanReturns);
        gradient = covMatrix.subtractVectors(gradient, meanReturnsScaled);

        // Check for convergence
        normGradient = covMatrix.norm(gradient);
        if (normGradient < tolerance) {
            break;  // Convergence achieved
        }

        if (iteration == 0) {
            direction = gradient;
        } else {
            dotProduct = covMatrix.dotProduct(gradient, gradient);
            beta = dotProduct / normGradient;

            direction = covMatrix.addVectors(gradient, covMatrix.multiplyVector(beta, prevDirection));
        }

        // Calculate step size
        dotProduct = covMatrix.dotProduct(gradient, direction);
        alpha = normGradient / dotProduct;

        // Update weights
        weights = covMatrix.subtractVectors(weights, covMatrix.multiplyVector(alpha, direction));

        // Update previous direction
        prevDirection = direction;
    }

    return weights;
}
