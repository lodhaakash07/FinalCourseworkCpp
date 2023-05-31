#include "Headers/Matrix.h""
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
/*
Matrix Matrix::transpose() const {
    int numRows = size();
    int numCols = front().size();

    Matrix result(numCols, numRows);

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            result[j][i] = (*this)[i][j];
        }
    }

    return result;
}



Matrix Matrix::operator*(const Matrix& other) const {
    // Check if the matrices are compatible for multiplication
    if (front().size() != other.size()) {
        throw std::runtime_error("Matrix multiplication error: Incompatible matrix dimensions");
    }

    int numRows = size();
    int numCols = other.front().size();
    int commonDim = front().size();

    Matrix result(numRows, std::vector<double>(numCols));

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < commonDim; ++k) {
                sum += (*this)[i][k] * other[k][j];
            }
            result[i][j] = sum;
        }
    }

    return result;
}

Matrix Matrix::operator/(double scalar) const {
    Matrix result(size(), std::vector<double>(front().size()));

    for (size_t i = 0; i < size(); ++i) {
        for (size_t j = 0; j < front().size(); ++j) {
            result[i][j] = (*this)[i][j] / scalar;
        }
    }

    return result;
} */