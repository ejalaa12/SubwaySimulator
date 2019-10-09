//
// Created by El Jawad Alaa on 06/10/2019.
//

#include "utilities/Random.h"

Random::Random(long pSeed) {
  mEngine.seed(pSeed);
}

int Random::nextInt(int pLower, int pUpper) {
  return std::uniform_int_distribution<int>{pLower, pUpper} (mEngine);
}

double Random::nextDouble(double pLower, double pUpper) {
  return std::uniform_real_distribution<double>{pLower, pUpper}(mEngine);
}
