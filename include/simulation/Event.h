//
// Created by ejalaa on 02/10/2019.
//

#ifndef SUBWAYSIMULATOR_EVENT_H
#define SUBWAYSIMULATOR_EVENT_H

#include <ostream>
#include "utilities/LocalDateTime.h"

class Event {

public:
  Event(std::string pCreator, LocalDateTime pScheduledTime, std::string pDescription);

protected:
  LocalDateTime mScheduledTime;
  std::string mDescription, mCreator;

public:
  const LocalDateTime &getScheduledTime() const;

  const std::string &getDescription() const;

  const std::string &getCreator() const;

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
