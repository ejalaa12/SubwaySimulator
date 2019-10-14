//
// Created by ejalaa on 02/10/2019.
//

#include "simulation/SimEngine.h"

std::string SimEngine::CLASS_NAME = "SimEngine";
long SimEngine::MAX_LOOPS  = 1000000L;


const LocalDateTime SimEngine::getCurrentSimTime() const {
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
  mLogger = Logger::getInstance();
}

void SimEngine::addEvent(Event *pNewEvent) {
  if (std::find(mEvents.begin(), mEvents.end(), pNewEvent) == mEvents.end()){
    mLogger->debug("adding event");
    mEvents.push_back(pNewEvent);
    mEvents.sort(PComp<Event>);
  } else{
    mLogger->warn("Adding an element that already exists (dismissed)");
  }
}

void SimEngine::removeEvent(Event *pEvent) {
  if (std::find(mEvents.begin(), mEvents.end(), pEvent) != mEvents.end()){
    mEvents.remove(pEvent);
  } else{
    mLogger->warn("Trying to remove and element that exists");
  }

}

void SimEngine::loop() {
  mLogger->info("Simulation started!");
  while (!(simHasEnded()))
    simStep();
  mLogger->info("Simulation ended !");
  std::ostringstream stream;
  stream << "Simulation had : ";
  stream << mLoops;
  mLogger->info(stream.str());
}

void SimEngine::simStep() {
  mLogger->info("sim step");
  // Get First event
  Event* currentEvent = mEvents.front();
  mEvents.pop_front();
  // break if the event is after endSimTime
  if (currentEvent->getScheduledTime() > mEndSimTime)
    return;
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

template<typename T>
bool SimEngine::PComp(const T *const &a, const T *const &b) {
    return *a < *b;
}
