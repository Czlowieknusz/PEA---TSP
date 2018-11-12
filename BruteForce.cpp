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
        CalculatedPath optimalPath(std::numeric_limits<unsigned>::max(), graphSize_);
        calculatedPath.visitedVertices_[startVertex] = true;
        Timer timer;
        timer.StartCounter();
        CalculatePath(startVertex, optimalPath, calculatedPath);
        double measured_time = timer.GetCounter();
        std::cout << "Minimal price is equal to: " << optimalPath.price_ << std::endl;
        std::cout << "Measured time is equal to: " << measured_time << "s." << std::endl;
        for (const auto node : optimalPath.path_) {
            std::cout << node << "; ";
        }
        return measured_time;
    } else {
        std::cout << "Vertex is not a part of the graph" << std::endl;
        return 0;
    }
}

void
BruteForce::CalculatePath(unsigned currentVertex, CalculatedPath &optimalPath, CalculatedPath calculatedPath) {
    for (unsigned vertex_index = 0; vertex_index < graphSize_; ++vertex_index) {
        if (!calculatedPath.visitedVertices_[vertex_index]) {
            CalculatedPath currentCalculatedPath(calculatedPath);
            currentCalculatedPath.visitedVertices_[vertex_index] = true;
            calculatedPath.price_ += graph_[currentVertex][vertex_index];
            if (SetMinPriceIfLastVertex(optimalPath, currentCalculatedPath)) {
                return;
            }
            CalculatePath(vertex_index, optimalPath, currentCalculatedPath);
        }
    }
}

bool BruteForce::SetMinPriceIfLastVertex(CalculatedPath &optimalPath, const CalculatedPath &calculatedPath) {
    bool isLastVertex = true;
    for (const auto isVisited : calculatedPath.visitedVertices_) {
        if (!isVisited) {
            isLastVertex = false;
            break;
        }
    }
    if (isLastVertex) {
        if (optimalPath.price_ > calculatedPath.price_) {
            optimalPath = calculatedPath;
        }
    }
    return isLastVertex;
}
