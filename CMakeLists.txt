cmake_minimum_required(VERSION 3.12)
project(PEA)

set(CMAKE_CXX_STANDARD 14)

add_executable(PEA main.cpp Edge.cpp Edge.h DataLoader.cpp DataLoader.h Menu.cpp Menu.h HeldKarp.cpp HeldKarp.h AlgorithmTSP.h BruteForce.cpp BruteForce.h Test.cpp Test.h Timer.cpp Timer.h)