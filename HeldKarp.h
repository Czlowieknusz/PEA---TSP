//
// Created by Jan Woźniak on 24.10.2018.
//

#ifndef PEA_HELDKARP_H
#define PEA_HELDKARP_H

#include "AlgorithmTSP.h"
#include <vector>

class HeldKarp : public AlgorithmTSP {
public:
    HeldKarp() = default;

    void CalculatePath(unsigned) final;

    unsigned CalculatePath(unsigned, const std::vector<bool> &);

    bool CheckIfAllVerticesAreVisited(const std::vector<bool> &);
};


#endif //PEA_HELDKARP_H
