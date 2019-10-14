#include <iostream>
#include "simulation/SimEngine.h"
#include "simulation/Entity.h"

class Person : public Entity {
public:
  enum Personality {
    Outgoing, Introvert, Normal
  };

  Person(SimEngine *pSimEngine, std::string pName, Personality pPersonality);

  void init();

  void organizeParty() const;

private:

  Personality mPersonality;
};

class Party : public Event {
public:
  Party(Person pOrganizer, LocalDateTime pScheduledTime);

  void doAction();
};


Person::Person(SimEngine *pSimEngine, std::string pName, Personality pPersonality)
    : Entity(pName, pSimEngine), mPersonality(pPersonality) {
}

void Person::init() {
  Logger *logger = Logger::getInstance();
  logger->info("Initialized Person");
  organizeParty();
}

void Person::organizeParty() const {
  dt::days d(2);
  LocalDateTime nextPartyTime = mSimEngine->getCurrentSimTime();
  nextPartyTime.plus(d);
  mSimEngine->addEvent(new Party(*this, nextPartyTime));
}


Party::Party(Person pOrganizer, LocalDateTime pScheduledTime)
    : Event(&pOrganizer, pScheduledTime, "Party !") {

}

void Party::doAction() {
  mLogger->info("Party Time !");
  dynamic_cast<Person *>(mCreator)->organizeParty();
}

int main() {
  SimEngine simEngine(1, LocalDateTime(2019, 3, 9, 14, 12, 3), LocalDateTime(2020, 3, 8, 15, 13, 12));
  Person jack(&simEngine, "Jack Doe", Person::Personality::Introvert);
  jack.init();
  simEngine.loop();

  return 0;
}