#include <iostream>
#include "simulation/SimEngine.h"
#include "simulation/Entity.h"


class RecurrentEvent: public Event{
private:
  SimEngine &mSimEngine; // TODO: events needs a reference to the simEngine
public:
  RecurrentEvent(std::string pCreator, LocalDateTime pScheduledTime, SimEngine &pSimEngine)
      : Event(std::move(pCreator), pScheduledTime, "recurrent event"), mSimEngine(pSimEngine) {
  }
  void doAction(){
    std::cout << "Action from recurrent event !" << std::endl;
    LocalDateTime dt = mScheduledTime;
//    dt::time_duration dur(24, 2, 1);
//    dt.plus(dur);
    dt.plus(dt::days(31));
    mSimEngine.addEvent(new RecurrentEvent("Event Generator 2", dt, mSimEngine));
  }
};

class EventGenerator : public Entity{
private:
  int mHdt;

public:
  EventGenerator(std::string pName, SimEngine &pSimEngine, int pHdt) : Entity(pName, pSimEngine), mHdt(pHdt) {

  }
  void init(){
    mSimEngine.addEvent(new RecurrentEvent("Event Generator", LocalDateTime(2019, 3, 8), mSimEngine));
  }
};

int main() {
  SimEngine simEngine(1, LocalDateTime(2019, 3, 9, 14, 12, 3), LocalDateTime(2020, 3, 8, 15, 13, 12));
  EventGenerator generator("Hehe", simEngine, 10);
  generator.init();
  simEngine.loop();

  return 0;
}