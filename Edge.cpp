//
// Created by Jan Woźniak on 07.10.2018.
//

#include "Edge.h"

Edge::Edge(const Edge &e) {
    nodeStart = e.nodeStart;
    nodeEnd = e.nodeEnd;
    weight = e.weight;
}

Edge::Edge(const std::string& start, const std::string& end, const double& weight) {
    this->nodeStart = start;
    this->nodeEnd = end;
    this->weight = weight;
}

bool Edge::operator==(const Edge &e) const {
    return this->weight == e.weight;
}

bool Edge::operator!=(const Edge &e) const {
    return *this == e;
}

bool Edge::operator<(const Edge &e) {
    return this->weight < e.weight;
}

bool Edge::operator>(const Edge &e) {
    return this->weight > e.weight;
}

std::ostream &operator<<(std::ostream &ost, const Edge &e) {
    ost << e.nodeStart << "->";
    ost << e.nodeEnd << ": ";
    ost << e.weight;
    return ost;
}
