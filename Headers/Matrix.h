#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
private:
    std::vector<std::vector<double> > data;

public:
    Matrix();
    Matrix(const std::vector<std::vector<double> >& inputData);
    Matrix(int numRows, int numCols)
    : data(numRows, std::vector<double>(numCols)) {}

    void setData(const std::vector<std::vector<double> >& inputData);
    void setData(int row, int col, double value);
    void appendRow(const std::vector<double>& row);
    std::vector<std::vector<double> > getData() const;

    Matrix operator*(const Matrix& other) const;
    Matrix crossProduct(const Matrix& other) const;
    double dotProduct(const Matrix& other) const;
    const std::vector<double> getColumn(int columnIndex);
    Matrix subset(int startIndex, int endIndex) const;
    Matrix transpose();
    Matrix operator*(const Matrix& other);
    Matrix operator/(double scalar);
    void transposeInPlace();
};



#endif // MATRIX_H
