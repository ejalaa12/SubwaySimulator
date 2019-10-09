//
// Created by ejalaa on 02/10/2019.
//

#ifndef SUBWAYSIMULATOR_ENTITY_H
#define SUBWAYSIMULATOR_ENTITY_H

#include "SimEngine.h"

class Entity {
protected:
  SimEngine &mSimEngine;
  std::string mName;

public:
  Entity(std::string pName, SimEngine &pSimEngine);
  virtual void init() = 0;

  const SimEngine &getSimEngine() const;

  const std::string &getName() const;

};

#endif //SUBWAYSIMULATOR_ENTITY_H
