//
// Created by Jan Woźniak on 07.10.2018.
//

#ifndef PEA_KRAWEDZ_H
#define PEA_KRAWEDZ_H

#include <iostream>

class Edge {
public:
    double weight;
    std::string nodeStart;
    std::string nodeEnd;
//    Edge *next, *previous;

    Edge() = default;

    Edge(const Edge &);

    Edge(const std::string &start, const std::string &end, const double &weight);

    friend std::ostream &operator<<(std::ostream &ost, const Edge &e);

    bool operator==(const Edge &e) const;

    bool operator<(const Edge &e);

    bool operator>(const Edge &e);

    bool operator!=(const Edge &e) const;

    Edge &operator=(const Edge &e) = default;
};


#endif //PEA_KRAWEDZ_H
