//
// Created by Евгений Горбуля on 04.04.2024.
//

#include "titanic.h"
#include <sstream>

void Titanic::readCSV(const std::string &path, stringVector &v) {
    std::fstream file(path);
    if(!file.is_open()) std::cout << "Wrong path";
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::string current;
        std::stringstream ss(line);
        //ss << line;
        std::vector < std::string > vec;
        while(std::getline(ss, current, ',')) {
            vec.push_back(current);
        }
        vec[vec.size() - 1] = std::string(vec[vec.size() - 1].begin(), vec[vec.size() - 1].end() - 1);
        v.push_back(vec);
    }
}
