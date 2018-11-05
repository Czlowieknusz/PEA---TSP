//
// Created by Jan Woźniak on 24.10.2018.
//

#include "HeldKarp.h"
#include <limits>
#include <algorithm>

HeldKarp::HeldKarp(std::string fileName) : AlgorithmTSP(std::move(fileName)) {
}

void HeldKarp::CalculatePath(unsigned startVertex) {
    if (startVertex >= 0 && startVertex < graphSize_) {
        std::vector<bool> visitedVertices(graphSize_, false);
        visitedVertices[startVertex] = true;
        unsigned minPrice = CalculatePath(startVertex, visitedVertices);
        //std::cout << "Min price is equal to: " << minPrice << std::endl;
    } else {
        std::cout << "Vertex is not a part of the graph" << std::endl;
    }
}

unsigned HeldKarp::CalculatePath(unsigned startVertex, const std::vector<bool> &visitedVertices) {
    if (CheckIfAllVerticesAreVisited(visitedVertices)) {
        return 0;
    }
    std::vector<unsigned> prices;
    for (unsigned i = 0; i < graphSize_; ++i) {
        if (!visitedVertices[i]) {
            std::vector<bool> currentVisitedVertices = visitedVertices;
            currentVisitedVertices[i] = true;
            prices.push_back(CalculatePath(i, currentVisitedVertices) + graph_[startVertex][i]);
        }
    }
    return *std::min_element(prices.begin(), prices.end());
}

bool HeldKarp::CheckIfAllVerticesAreVisited(const std::vector<bool> &visitedVertices) {
    for (const auto isVisited : visitedVertices) {
        if (!isVisited) {
            return false;
        }
    }
    return true;
}