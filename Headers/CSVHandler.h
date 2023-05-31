#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include "Matrix.h"
#include "FileHandler.h"
#include <vector>
#include <string>

class CSVHandler : public FileHandler {
public:
    Matrix readCSV(const std::string& filename);
    void writeDataToCSV(const std::vector<std::vector<double> >& data, const std::string& filename);
};

#endif // CSVHANDLER_H