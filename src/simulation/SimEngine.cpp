//
// Created by ejalaa on 02/10/2019.
//

#include "simulation/SimEngine.h"

const LocalDateTime &SimEngine::getCurrentSimTime() const {
  return mCurrentSimTime;
}

int SimEngine::getLoops() const {
  return mLoops;
}

const Random &SimEngine::getRandom() const {
  return mRandom;
}

SimEngine::SimEngine(long pSeed, LocalDateTime pStartSimTime, LocalDateTime pEndSimTime) :
    mRandom(pSeed), mStartSimTime(pStartSimTime), mCurrentSimTime(pStartSimTime), mEndSimTime(pEndSimTime){
  this->mLoops = 0;
}

void SimEngine::addEvent(Event *pNewEvent) {
  if (std::find(mEvents.begin(), mEvents.end(), pNewEvent) == mEvents.end()){
    std::cout << "adding event" << std::endl;   // TODO: create Logger Singleton class
    mEvents.push_back(pNewEvent);
    mEvents.sort(); // TODO: change sort according to pointer
  } else{
    std::cout << "Adding an element that already exists (dismissed)" << std::endl;
  }
}

void SimEngine::removeEvent(Event *pEvent) {
  if (std::find(mEvents.begin(), mEvents.end(), pEvent) != mEvents.end()){
    mEvents.remove(pEvent);
  } else{
    std::cout << "Trying to remove and element that exists" << std::endl;
  }

}

void SimEngine::loop() {
  std::cout << "Simulation started!" << std::endl;
  while (!(simHasEnded()))
    simStep();
  std::cout << "Simulation ended !" << std::endl;
  std::cout << "Simulation had " << mLoops << " loops" << std::endl;
}

void SimEngine::simStep() {
  std::cout << "sim step" << std::endl;
  // Get First event
  Event* currentEvent = mEvents.front();
  mEvents.pop_front();
  // break if the event is after endSimTime
  if (currentEvent->getScheduledTime() > mEndSimTime)
    return;
  std::cout << "Current event is" << currentEvent << std::endl;
  // Update simulation time with current event time
  mCurrentSimTime = currentEvent->getScheduledTime();
  // Do the action of this event and get all generated events
  currentEvent->doAction();
  // Increment loops
  mLoops += 1;

}

bool SimEngine::simHasEnded() {
  return mEvents.empty() || mCurrentSimTime >= mEndSimTime || mLoops >= MAX_LOOPS;
}
