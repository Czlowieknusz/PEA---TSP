//
// Created by Jan Woźniak on 24.10.2018.
//

#ifndef PEA_BRUTEFORCE_H
#define PEA_BRUTEFORCE_H

#include "AlgorithmTSP.h"
#include <vector>

class BruteForce : public AlgorithmTSP {
public:
    explicit BruteForce(std::string);

    double CalculatePath(unsigned) final;

<<<<<<< HEAD
    void CalculatePath(unsigned currentVertex, CalculatedPath &optimalPath, CalculatedPath calculatedPath);

    bool SetMinPriceIfLastVertex(CalculatedPath& optimalPath, const CalculatedPath &calculatedPath);
=======
    void CalculatePath(unsigned currentVertex, unsigned &minPrice,
                       unsigned currentPrice, const std::vector<bool> &visitedVertexes);

    bool SetMinPriceIfLastVertex(unsigned &minPrice,
                                 unsigned currentPrice, std::vector<bool> visitedVertexes);
>>>>>>> parent of 15a589b... BruteForce in final form.
};


#endif //PEA_BRUTEFORCE_H
