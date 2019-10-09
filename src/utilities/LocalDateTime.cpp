//
// Created by El Jawad Alaa on 03/10/2019.
//

#include "utilities/LocalDateTime.h"

LocalDateTime::LocalDateTime(int pYear, int pMonth, int pDay, int pHour, int pMin, int pSeconds) {
  mDateTime = dt::ptime(dt::date(pYear, pMonth, pDay), dt::time_duration(pHour, pMin, pSeconds));
}

bool LocalDateTime::operator==(const LocalDateTime &pRhs) const {
  return mDateTime == pRhs.mDateTime;
}

bool LocalDateTime::operator!=(const LocalDateTime &pRhs) const {
  return !(pRhs == *this);
}

bool LocalDateTime::operator<(const LocalDateTime &pRhs) const {
  return mDateTime < pRhs.mDateTime;
}

bool LocalDateTime::operator>(const LocalDateTime &pRhs) const {
  return pRhs < *this;
}

bool LocalDateTime::operator<=(const LocalDateTime &pRhs) const {
  return !(pRhs < *this);
}

bool LocalDateTime::operator>=(const LocalDateTime &pRhs) const {
  return !(*this < pRhs);
}

std::ostream &operator<<(std::ostream &pOs, const LocalDateTime &pTime) {
  pOs << "mDateTime: " << pTime.mDateTime;
  return pOs;
}

void LocalDateTime::plus(dt::time_duration pTimeDuration) {
  mDateTime += pTimeDuration;
}

void LocalDateTime::plus(dt::days pDays) {
  mDateTime += pDays;
}
