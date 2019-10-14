//
// Created by ejalaa on 02/10/2019.
//

#include "simulation/Entity.h"


const std::string &Entity::getName() const {
  return mName;
}

Entity::Entity(std::string pName, SimEngine *pSimEngine): mName(pName), mSimEngine(pSimEngine) {

}
