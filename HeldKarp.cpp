//
// Created by Jan Woźniak on 24.10.2018.
//

#include "HeldKarp.h"
#include <limits>
#include <algorithm>
#include "Timer.h"

HeldKarp::HeldKarp(std::string fileName) : AlgorithmTSP(std::move(fileName)) {
}

double HeldKarp::CalculatePath(unsigned startVertex) {
    if (startVertex >= 0 && startVertex < graphSize_) {
        CalculatedPath calculatedPath(0, graphSize_);
        calculatedPath.visitedVertices_[startVertex] = true;
        calculatedPath.path_.push_back(startVertex);

        Timer timer;
        timer.StartCounter();
        auto optimalPath = CalculatePath(startVertex, calculatedPath);
        optimalPath.price_ += graph_[optimalPath.path_[graphSize_ - 1]][startVertex];
        optimalPath.path_.push_back(startVertex);
        double measured_time = timer.GetCounter();
        std::cout << "Min price is equal to: " << optimalPath.price_ << std::endl;
        std::cout << "Measured time is equal to: " << measured_time << std::endl;
        for (const auto node : optimalPath.path_) {
            std::cout << node << "; ";
        }
        std::cout << std::endl;
        return measured_time;
    } else {
        std::cout << "Vertex is not a part of the graph" << std::endl;
        return 0;
    }
}

CalculatedPath
HeldKarp::CalculatePath(unsigned startVertex, const CalculatedPath &calculatedPath) {
    if (CheckIfAllVerticesAreVisited(calculatedPath.visitedVertices_)) {
        return calculatedPath;
    }
    std::vector<CalculatedPath> pathsFound;
    for (unsigned i = 0; i < graphSize_; ++i) {
        if (!calculatedPath.visitedVertices_.at(i)) {
            CalculatedPath currentCalculatedPath(calculatedPath);
            currentCalculatedPath.visitedVertices_.at(i) = true;
            currentCalculatedPath.path_.push_back(i);
            CalculatedPath calculatedPathToPushBack = CalculatePath(i, currentCalculatedPath);
            calculatedPathToPushBack.price_ += graph_[startVertex][i];
            pathsFound.push_back(calculatedPathToPushBack);
        }
    }
    return pathsFound[FindIndexOfOptimalPath(pathsFound)];
}

unsigned HeldKarp::FindIndexOfOptimalPath(const std::vector<CalculatedPath> &paths) {
    unsigned indexOfOptimalPath = 0;
    unsigned minPrice = std::numeric_limits<unsigned>::max();
    for (unsigned i = 0; i < paths.size(); ++i) {
        if (paths[i].price_ < minPrice) {
            minPrice = paths[i].price_;
            indexOfOptimalPath = i;
        }
    }
    return indexOfOptimalPath;
}

bool HeldKarp::CheckIfAllVerticesAreVisited(const std::vector<bool> &visitedVertices) {
    for (const auto isVisited : visitedVertices) {
        if (!isVisited) {
            return false;
        }
    }
    return true;
}