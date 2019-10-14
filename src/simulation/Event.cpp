//
// Created by ejalaa on 02/10/2019.
//

#include <utility>
#include "simulation/Event.h"
#include "simulation/Entity.h"

Event::Event(Entity *pCreator, LocalDateTime pScheduledTime, std::string pDescription)
    : mScheduledTime(pScheduledTime), mCreator(pCreator), mDescription(std::move(pDescription)) {
  mLogger = Logger::getInstance();

}

bool Event::operator<(const Event &pRhs) const {
  return mScheduledTime < pRhs.mScheduledTime;
}

bool Event::operator>(const Event &pRhs) const {
  return pRhs < *this;
}

bool Event::operator<=(const Event &pRhs) const {
  return !(pRhs < *this);
}

bool Event::operator>=(const Event &pRhs) const {
  return !(*this < pRhs);
}

bool Event::operator==(const Event &pRhs) const {
  return mScheduledTime == pRhs.mScheduledTime &&
         mDescription == pRhs.mDescription &&
         mCreator == pRhs.mCreator;
}

bool Event::operator!=(const Event &pRhs) const {
  return !(pRhs == *this);
}

const LocalDateTime &Event::getScheduledTime() const {
  return mScheduledTime;
}

const std::string &Event::getDescription() const {
  return mDescription;
}

std::ostream &operator<<(std::ostream &pOs, const Event &pEvent) {
  pOs << "mScheduledTime: " << pEvent.mScheduledTime << " mDescription: " << pEvent.mDescription << " mCreator: "
      << pEvent.mCreator;
  return pOs;
}

Entity *Event::getCreator() const {
  return mCreator;
}

