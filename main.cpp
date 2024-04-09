//
// Created by Евгений Горбуля on 04.04.2024.
//
#include "titanic.h"
#include <iostream>
#include <string>

const std::string PATH = "../data/train.csv";

int main() {
//    std::cout << CSVFIELDS::a << " " << CSVFIELDS::b << " " << CSVFIELDS::c;
    stringVector table;
    Titanic::readCSV(PATH, table);
    Titanic t(table);
    t.sortPassengers();
    std::cout << t;
//    for(const std::vector < std::string > &vec : table) {
//        for(const std::string &elem : vec) {
//            std::cout << elem << " ";
//        }
//        std::cout << '\n';
//    }
}