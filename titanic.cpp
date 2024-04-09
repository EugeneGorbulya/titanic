//
// Created by Евгений Горбуля on 04.04.2024.
//

#include "titanic.h"
#include <sstream>
#include <algorithm>

const double WEIGHTS[3] = {0.5, 0.25, 0.25};

std::ostream &operator<<(std::ostream &stream, const Passenger &cur) {
    stream << cur.name << " " << cur.rate << " " << cur.isSurvived << "\n";
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const Titanic &cur) {
    for (const Passenger &p: cur._passengers) {
        stream << p;
    }
    return stream;
}

double Passenger::ratePassenger(const Passenger &p) {
    return (1.0 - p.age / 100.0) * WEIGHTS[0] + ((1.0 + (p.sex == "female" ? 1.0 : 0.0)) / 2) * WEIGHTS[1] + 1.0 / p.pClass * WEIGHTS[2];
}

void Titanic::addPassenger(Passenger &p) {
    _passengers.push_back(p);
}

bool cmp(const Passenger &a, const Passenger &b) {
    return a.rate > b.rate;
}

void Titanic::sortPassengers() {
    std::sort(_passengers.begin(), _passengers.end(), cmp);
}

Titanic::Titanic(const stringVector &v) {
    for (const stringVector::value_type &el: v) {
        Passenger p{el[static_cast<int>(CSVFIELDS::Name)], std::stoi(el[static_cast<int>(CSVFIELDS::Age)]),
                    el[static_cast<int>(CSVFIELDS::Sex)],
                    static_cast<bool>(std::stoi(el[static_cast<int>(CSVFIELDS::Survived)])),
                    std::stoi(el[static_cast<int>(CSVFIELDS::Pclass)])};
        p.rate = Passenger::ratePassenger(p);
        addPassenger(p);
    }
}

void Titanic::readCSV(const std::string &path, stringVector &v) {
    std::fstream file(path);
    if (!file.is_open()) std::cout << "Wrong path";
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::string current;
        std::stringstream ss(line);
        //ss << line;
        std::vector<std::string> vec;
        while (std::getline(ss, current, ',')) {
            if (current == "") {
                current = "28";
            }
            vec.push_back(current);
        }
        vec[vec.size() - 1] = std::string(vec[vec.size() - 1].begin(), vec[vec.size() - 1].end() - 1);
        v.push_back(vec);
    }
}
