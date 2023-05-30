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

Matrix Matrix::operator*(const Matrix& other) {
    // Check if the matrices are compatible for multiplication
    if (data[0].size() != other.data.size()) {
        throw std::runtime_error("Matrix multiplication error: Incompatible matrix dimensions");
    }

    int numRows = data.size();
    int numCols = other.data[0].size();
    int commonDim = data[0].size();

    Matrix result(numRows, numCols);

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < commonDim; ++k) {
                sum += data[i][k] * other.data[k][j];
            }
            result.setData(i, j, sum);
        }
    }

    return result;
}

Matrix Matrix::operator/(double scalar)  {
    Matrix result(data.size(), data[0].size());

    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            result.setData(i, j, data[i][j] / scalar);
        }
    }

    return result;
}


Matrix Matrix::transpose() {
    int numRows = data.size();
    int numCols = data[0].size();

    Matrix result(numCols, numRows);

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            result.setData(j, i, data[i][j]);
        }
    }

    return result;
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

const std::vector<double> Matrix::getColumn(int columnIndex) {
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

Matrix Matrix::subset(int startIndex, int endIndex) const {
    if (startIndex < 0 || endIndex >= data.size() || startIndex > endIndex) {
        throw std::runtime_error("Invalid indices for subsetting");
    }

    std::vector<std::vector<double> > subsetData;
    for (int i = startIndex; i < endIndex; ++i) {
        subsetData.push_back(data[i]);
    }
    
    return Matrix(subsetData);
}

void Matrix::transposeInPlace() {
    int numRows = data.size();
    int numCols = data[0].size();

    std::vector<std::vector<double> > transposedData(numCols, std::vector<double>(numRows));

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            transposedData[j][i] = data[i][j];
        }
    }

    data = transposedData;
}