//
// Created by ejalaa on 02/10/2019.
//

#ifndef SUBWAYSIMULATOR_SIMENGINE_H
#define SUBWAYSIMULATOR_SIMENGINE_H
#include <string>
#include <list>
#include "utilities/LocalDateTime.h"
#include "Event.h"
#include "utilities/Random.h"
#include <algorithm>
#include <functional>


class SimEngine {
private:
  inline static std::string CLASS_NAME = "SimEngine";
  inline static long MAX_LOOPS = 1000000L;

  std::list<Event*> mEvents;
  LocalDateTime mStartSimTime, mCurrentSimTime, mEndSimTime;
  int mLoops;
  Random mRandom;

public:
  SimEngine(long pSeed, LocalDateTime pStartSimTime, LocalDateTime pEndSimTime);
  void addEvent(Event *pNewEvent);
  void removeEvent(Event *pEvent);
  void loop();

private:
  void simStep();
  bool simHasEnded();

public:
  const LocalDateTime &getCurrentSimTime() const;

  int getLoops() const;

  const Random &getRandom() const;


};

#endif //SUBWAYSIMULATOR_SIMENGINE_H
