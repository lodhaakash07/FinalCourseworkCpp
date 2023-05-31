#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>

class FileHandler {
public:
    std::vector<std::string> readFile(const std::string& filename);
};

#endif // FILEHANDLER_H