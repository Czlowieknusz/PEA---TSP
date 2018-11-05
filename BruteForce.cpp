//
// Created by Jan Woźniak on 24.10.2018.
//

#include "BruteForce.h"
#include <limits>

BruteForce::BruteForce(std::string fileName) : AlgorithmTSP(std::move(fileName)) {
}

void BruteForce::CalculatePath(unsigned startVertex) {
    if (startVertex >= 0 && startVertex < graphSize_) {
        unsigned minPrice = std::numeric_limits<unsigned>::max();
        std::vector<bool> visitedVertexes(graphSize_, false);
        visitedVertexes[startVertex] = true;
        CalculatePath(startVertex, minPrice, 0, visitedVertexes);
        std::cout << "Minimal price is equal to " << minPrice << std::endl;
    } else {
        std::cout << "Vertex is not a part of the graph" << std::endl;
    }
}

void
BruteForce::CalculatePath(unsigned currentVertex, unsigned &minPrice, unsigned currentPrice,
                          const std::vector<bool> &visitedVertexes) {
    for (unsigned vertex_index = 0; vertex_index < graphSize_; ++vertex_index) {
        if (!visitedVertexes[vertex_index]) {
            std::vector<bool> currentVisitedVertices = visitedVertexes;
            currentVisitedVertices[vertex_index] = true;
            unsigned iteration_price = currentPrice + graph_[currentVertex][vertex_index];
            if (SetMinPriceIfLastVertex(minPrice, iteration_price, currentVisitedVertices)) {
                return;
            }
            CalculatePath(vertex_index, minPrice, iteration_price, currentVisitedVertices);
        }
    }
}

bool BruteForce::SetMinPriceIfLastVertex(unsigned &minPrice, unsigned currentPrice, std::vector<bool> visitedVertexes) {
    bool isLastVertex = true;
    for (const auto isVisited : visitedVertexes) {
        if (!isVisited) {
            isLastVertex = false;
            break;
        }
    }
    if (isLastVertex) {
        if (minPrice > currentPrice) {
            minPrice = currentPrice;
        }
    }
    return isLastVertex;
}
