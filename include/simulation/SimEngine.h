//
// Created by ejalaa on 02/10/2019.
//

#ifndef SUBWAYSIMULATOR_SIMENGINE_H
#define SUBWAYSIMULATOR_SIMENGINE_H
#include <string>
#include <list>
#include <boost/date_time.hpp>
#include "Event.h"


class SimEngine {
private:
  inline static std::string className = "SimEngine";
  inline static long MAX_LOOPS = 1000000L;

  std::list<Event> events;
  boost::gregorian::date startSimTime, currentSimTime, endSimTime;
};

#endif //SUBWAYSIMULATOR_SIMENGINE_H
