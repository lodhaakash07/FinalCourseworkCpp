#include "Headers/Matrix.h""
#include <stdexcept>

Matrix::Matrix() {}

Matrix::Matrix(const std::vector<std::vector<double> >& inputData) : data(inputData) {}



void Matrix::setData(const std::vector<std::vector<double> >& inputData) {
    data = inputData;
}

void Matrix::appendRow(const std::vector<double>& row) {
    if (!data.empty() && row.size() != data[0].size()) {
        throw std::runtime_error("Cannot append row: Incompatible size");
    }
    data.push_back(row);
}

std::vector<std::vector<double> > Matrix::getData() const {
    return data;
}

Matrix Matrix::operator*(const Matrix& other) const {
    // Implementation of matrix multiplication
}

Matrix Matrix::crossProduct(const Matrix& other) const {
    
}

double Matrix::dotProduct(const Matrix& other) const {
    if (data.empty() || other.data.empty() || data.size() != other.data.size() ||
        data[0].size() != other.data[0].size()) {
        throw std::runtime_error("Invalid dot product operation: Matrices must have the same size");
    }

    double result = 0.0;
    int rows = data.size();
    int cols = data[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result += data[i][j] * other.data[i][j];
        }
    }

    return result;
}

std::vector<double> Matrix::getColumn(int columnIndex) const {
    std::vector<double> column;

    if (!data.empty()) {
        for (const auto& row : data) {
            if (columnIndex < row.size()) {
                column.push_back(row[columnIndex]);
            }
        }
    }

    return column;
}

void Matrix::setData(int row, int col, double value) {
    if (row >= 0 && row < data.size() && col >= 0 && col < data[row].size()) {
        data[row][col] = value;
    } else {
        throw std::runtime_error("Invalid matrix index");
    }
}