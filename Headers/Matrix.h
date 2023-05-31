#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix : public std::vector<std::vector<double> > {
public:
    void appendRow(const std::vector<double>& row);
    Matrix subset(int startIndex, int endIndex) const;
    std::vector<double> subtractVectors(const std::vector<double>& a, const std::vector<double>& b) const;
    std::vector<double> multiplyMatrixVector(const Matrix& m, const std::vector<double>& v) const;
    std::vector<double> multiplyVector(double scalar, const std::vector<double>& v) const;
    std::vector<double> addVectors(const std::vector<double>& a, const std::vector<double>& b) const;
    double dotProduct(const std::vector<double>& a, const std::vector<double>& b) const;
    double norm(const std::vector<double>& v) const;
};

#endif // MATRIX_H
