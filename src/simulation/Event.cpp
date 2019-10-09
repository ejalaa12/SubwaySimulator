//
// Created by ejalaa on 02/10/2019.
//

#include "simulation/Event.h"


Event::Event(std::string pCreator, LocalDateTime pScheduledTime, std::string pDescription) :
mCreator(pCreator), mScheduledTime(pScheduledTime), mDescription(pDescription) {

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

const std::string &Event::getCreator() const {
  return mCreator;
}

std::ostream &operator<<(std::ostream &pOs, const Event &pEvent) {
  pOs << "mScheduledTime: " << pEvent.mScheduledTime << " mDescription: " << pEvent.mDescription << " mCreator: "
      << pEvent.mCreator;
  return pOs;
}
