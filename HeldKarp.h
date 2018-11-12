//
// Created by Jan Woźniak on 24.10.2018.
//

#ifndef PEA_HELDKARP_H
#define PEA_HELDKARP_H

#include "AlgorithmTSP.h"
#include <vector>

class HeldKarp : public AlgorithmTSP {
public:
    explicit HeldKarp(std::string);

    double CalculatePath(unsigned) final;

    CalculatedPath CalculatePath(unsigned, CalculatedPath &&);

    unsigned FindIndexOfOptimalPath(const std::vector<CalculatedPath>&);

    bool CheckIfAllVerticesAreVisited(const std::vector<bool > &);
};


#endif //PEA_HELDKARP_H
