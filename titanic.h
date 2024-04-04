//
// Created by Евгений Горбуля on 04.04.2024.
//

#ifndef TITANIC_TITANIC_H
#define TITANIC_TITANIC_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//typedef std::vector < std::vector < std::string > > stringVector;
using stringVector = std::vector < std::vector < std::string > >;

class Titanic {
public:
    static void readCSV(const std::string &path, stringVector &v);

};

#endif //TITANIC_TITANIC_H
