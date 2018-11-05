//
// Created by Jan Woźniak on 24.10.2018.
//

#ifndef PEA_BRUTEFORCE_H
#define PEA_BRUTEFORCE_H

#include "AlgorithmTSP.h"
#include <vector>

class BruteForce : public AlgorithmTSP {
public:
    BruteForce() = default;

    void CalculatePath(unsigned) final;

    void CalculatePath(unsigned currentVertex, unsigned &minPrice,
                       unsigned currentPrice, const std::vector<bool> &visitedVertexes);

    bool SetMinPriceIfLastVertex(unsigned &minPrice,
                                 unsigned currentPrice, std::vector<bool> visitedVertexes);
};


#endif //PEA_BRUTEFORCE_H
