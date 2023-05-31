#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix : public std::vector<std::vector<double> > {
public:
    

    void appendRow(const std::vector<double>& row);
    Matrix subset(int startIndex, int endIndex) const;
   // Matrix transpose() const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator/(double scalar) const;
};

#endif // MATRIX_H