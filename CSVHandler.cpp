#include "Headers/CSVHandler.h"
#include <sstream>


Matrix CSVHandler::readCSV(const std::string& filename) {
    std::vector<std::string> lines = readFile(filename);
    Matrix data;

    for (const std::string& line : lines) {
        std::vector<double> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(std::stod(cell));
        }

        data.appendRow(row);
    }
    return data;
}