#include "Headers/CSVHandler.h"
#include <sstream>
#include <fstream>

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

void CSVHandler::writeDataToCSV(const std::vector<std::vector<double> >& data, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        // Write the column headers
        file << "Window, Target Return, In-sample Mean, In-sample Covariance, Out-sample Mean, Out-sample Covariance\n";

        // Write the data
        for (const auto& row : data) {
            for (int i = 0; i < row.size(); ++i) {
                file << row[i];
                if (i != row.size() - 1) {
                    file << ", ";
                }
            }
            file << "\n";
        }

        file.close();
    }
    else {
    }
}