#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include "Matrix.h"
#include "FileHandler.h"
#include <vector>
#include <string>

class CSVHandler : public FileHandler {
public:
    Matrix readCSV(const std::string& filename);
};

#endif // CSVHANDLER_H
