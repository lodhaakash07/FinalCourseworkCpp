#include "Headers/FileHandler.h""
#include <fstream>
#include <iostream>

std::vector<std::string> FileHandler::readFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Failed to open the file: " << filename << std::endl;
        return lines;
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}