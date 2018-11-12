//
// Created by Jan Woźniak on 24.10.2018.
//

#include "BruteForce.h"
#include <limits>
#include "Timer.h"

BruteForce::BruteForce(std::string fileName) : AlgorithmTSP(std::move(fileName)) {
}

double BruteForce::CalculatePath(unsigned startVertex) {
    if (startVertex >= 0 && startVertex < graphSize_) {
        CalculatedPath calculatedPath(0, graphSize_);
        unsigned minPrice = std::numeric_limits<unsigned>::max();
        calculatedPath.visitedVertices_[startVertex] = true;
        Timer timer;
        timer.StartCounter();
        CalculatePath(startVertex, minPrice, calculatedPath);
        double measured_time = timer.GetCounter();
        //std::cout << "Minimal price is equal to: " << minPrice << std::endl;
        //std::cout << "Measured time is equal to: " << measured_time << "s." << std::endl;
        return measured_time;
    } else {
        std::cout << "Vertex is not a part of the graph" << std::endl;
        return 0;
    }
}

void
BruteForce::CalculatePath(unsigned currentVertex, unsigned &minPrice, CalculatedPath calculatedPath) {
    for (unsigned vertex_index = 0; vertex_index < graphSize_; ++vertex_index) {
        if (!calculatedPath.visitedVertices_[vertex_index]) {
            CalculatedPath currentCalculatedPath(calculatedPath);
            currentCalculatedPath.visitedVertices_[vertex_index] = true;
            calculatedPath.price_ += graph_[currentVertex][vertex_index];
            if (SetMinPriceIfLastVertex(minPrice, currentCalculatedPath)) {
                return;
            }
            CalculatePath(vertex_index, minPrice, currentCalculatedPath);
        }
    }
}

bool BruteForce::SetMinPriceIfLastVertex(unsigned &minPrice, const CalculatedPath &calculatedPath) {
    bool isLastVertex = true;
    for (const auto isVisited : calculatedPath.visitedVertices_) {
        if (!isVisited) {
            isLastVertex = false;
            break;
        }
    }
    if (isLastVertex) {
        if (minPrice > calculatedPath.price_) {
            minPrice = calculatedPath.price_;
        }
    }
    return isLastVertex;
}
