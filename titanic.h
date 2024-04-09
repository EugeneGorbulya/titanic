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

enum class CSVFIELDS {
    PassengerId,Survived,Pclass,Name,Sex,Age,SibSp,Parch,Ticket,Fare,Cabin,Embarked
};

struct Passenger {
    std::string name;
    int age;
    std::string sex;
    bool isSurvived;
    int pClass;
    double rate;
//    Passenger(std::string name, int age, std::string sex, bool isSurvived):
    friend std::ostream& operator<< (std::ostream &stream, const Passenger &cur);
    static double ratePassenger(const Passenger &p);
};

class Titanic {
public:
    static void readCSV(const std::string &path, stringVector &v);
    Titanic(const stringVector &v);
    void addPassenger(Passenger &p);
    friend std::ostream& operator<< (std::ostream &stream, const Titanic &cur);
    void sortPassengers();
private:
    std::vector < Passenger > _passengers;

};

#endif //TITANIC_TITANIC_H
