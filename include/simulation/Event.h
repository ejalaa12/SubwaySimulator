//
// Created by ejalaa on 02/10/2019.
//

#ifndef SUBWAYSIMULATOR_EVENT_H
#define SUBWAYSIMULATOR_EVENT_H

#include <ostream>
#include "utilities/Logger.h"
#include "utilities/LocalDateTime.h"


class Entity;

class Event {

public:
  Event(Entity* pCreator, LocalDateTime pScheduledTime, std::string pDescription);

protected:
  Entity *mCreator;
public:
  Entity *getCreator() const;

protected:
  LocalDateTime mScheduledTime;
  std::string mDescription;
  Logger* mLogger;

public:

  const LocalDateTime &getScheduledTime() const;

  const std::string &getDescription() const;

  virtual void doAction() = 0;

  bool operator==(const Event &pRhs) const;

  bool operator!=(const Event &pRhs) const;

  bool operator<(const Event &pRhs) const;

  bool operator>(const Event &pRhs) const;

  bool operator<=(const Event &pRhs) const;

  bool operator>=(const Event &pRhs) const;

  friend std::ostream &operator<<(std::ostream &pOs, const Event &pEvent);

};

#endif //SUBWAYSIMULATOR_EVENT_H
