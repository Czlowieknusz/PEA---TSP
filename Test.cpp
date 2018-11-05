//
// Created by Jan Woźniak on 05.11.2018.
//

#include "Test.h"
#include "BruteForce.h"
#include "HeldKarp.h"
#include "Timer.h"
#include <vector>

void Test::MakeTests() {
    std::vector<std::string> fileNames(
            {"Graph_six.txt", "Graph_seven.txt", "Graph_eight.txt", "Graph_nine.txt", "Graph_ten.txt", "Graph_eleven.txt"});
    for (auto &fileName : fileNames) {
        std::cout << "File name is " << fileName << std::endl;
        CalculateBruteForce(50, fileName);
        CalculateHeldKarp(50, fileName);
    }
}

void Test::CalculateBruteForce(unsigned numberOfTests, std::string fileName) {
    BruteForce bruteForce(std::move(fileName));
    Timer timer;
    std::vector<double> measurements(numberOfTests);
    for (unsigned i = 0; i < numberOfTests; ++i) {
        timer.StartCounter();
        bruteForce.CalculatePath(0);
        measurements[i] = timer.GetCounter();
    }
    double average_time = 0;
    for (auto &measurement : measurements) {
        average_time +=measurement;
        //std::cout << measurement << std::endl;
    }
    average_time /=numberOfTests;
    std::cout << "BruteForce: " << " ; " << average_time << std::endl;
}

void Test::CalculateHeldKarp(unsigned numberOfTests, std::string fileName) {
    HeldKarp heldKarp(std::move(fileName));
    Timer timer;
    std::vector<double> measurements(numberOfTests);
    for (unsigned i = 0; i < numberOfTests; ++i) {
        timer.StartCounter();
        heldKarp.CalculatePath(0);
        measurements[i] = timer.GetCounter();
    }
    double average_time = 0;
    for (auto &measurement : measurements) {
        average_time +=measurement;
        //std::cout << measurement << std::endl;
    }
    average_time /=numberOfTests;
    std::cout << "HeldKarp: " << " ; " << average_time << std::endl;
}