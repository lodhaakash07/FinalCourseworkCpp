#include "Headers/Matrix.h"
#include <stdexcept>

void Matrix::appendRow(const std::vector<double>& row) {
    if (!empty() && row.size() != front().size()) {
        throw std::runtime_error("Cannot append row: Incompatible size");
    }
    push_back(row);
}

Matrix Matrix::subset(int startIndex, int endIndex) const {
    if (startIndex < 0 || endIndex >= size() || startIndex > endIndex) {
        throw std::runtime_error("Invalid indices for subsetting");
    }

    Matrix subsetData;
    for (int i = startIndex; i < endIndex; ++i) {
        subsetData.push_back((*this)[i]);
    }

    return subsetData;
}

std::vector<double> Matrix::subtractVectors(const std::vector<double>& a, const std::vector<double>& b) const {
    if (a.size() != b.size()) {
        throw std::runtime_error("Cannot subtract vectors: Incompatible sizes");
    }
    std::vector<double> result(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        result[i] = a[i] - b[i];
    }
    return result;
}

std::vector<double> Matrix::multiplyMatrixVector(const Matrix& m, const std::vector<double>& v) const {
    if (m.front().size() != v.size()) {
        throw std::runtime_error("Cannot multiply matrix and vector: Incompatible sizes");
    }
    std::vector<double> result(m.size(), 0.0);
    for (size_t i = 0; i < m.size(); i++) {
        for (size_t j = 0; j < m[i].size(); j++) {
            result[i] += m[i][j] * v[j];
        }
    }
    return result;
}

std::vector<double> Matrix::multiplyVector(double scalar, const std::vector<double>& v) const {
    std::vector<double> result(v.size());
    for (size_t i = 0; i < v.size(); i++) {
        result[i] = scalar * v[i];
    }
    return result;
}

std::vector<double> Matrix::addVectors(const std::vector<double>& a, const std::vector<double>& b) const {
    if (a.size() != b.size()) {
        throw std::runtime_error("Cannot add vectors: Incompatible sizes");
    }
    std::vector<double> result(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        result[i] = a[i] + b[i];
    }
    return result;
}

double Matrix::dotProduct(const std::vector<double>& a, const std::vector<double>& b) const {
    if (a.size() != b.size()) {
        throw std::runtime_error("Cannot compute dot product: Incompatible sizes");
    }
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

double Matrix::norm(const std::vector<double>& v) const {
    return std::sqrt(dotProduct(v, v));
}
