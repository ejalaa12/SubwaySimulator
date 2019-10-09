//
// Created by El Jawad Alaa on 06/10/2019.
//

#ifndef SUBWAYSIMULATOR_RANDOM_H
#define SUBWAYSIMULATOR_RANDOM_H

#include <random>

class Random {
private:
  std::default_random_engine mEngine;

public:
  Random(long pSeed);
  int nextInt(int pLower, int pUpper);
  double nextDouble(double pLower, double pUpper);

};


#endif //SUBWAYSIMULATOR_RANDOM_H
