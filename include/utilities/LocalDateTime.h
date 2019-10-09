//
// Created by El Jawad Alaa on 03/10/2019.
//

#ifndef SUBWAYSIMULATOR_LOCALDATETIME_H
#define SUBWAYSIMULATOR_LOCALDATETIME_H

#include <boost/date_time.hpp>
#include <ostream>
#include "boost/date_time/posix_time/posix_time.hpp"

namespace dt{
  using namespace boost::posix_time;
  using namespace boost::gregorian;
}

class LocalDateTime {
private:
  dt::ptime mDateTime;
public:
  LocalDateTime(int pYear, int pMonth, int pDay, int pHour=0, int pMin=0, int pSeconds=0);

  void plus(dt::time_duration pTimeDuration);

  void plus(dt::days pDays);

  bool operator<(const LocalDateTime &pRhs) const;

  bool operator>(const LocalDateTime &pRhs) const;

  bool operator<=(const LocalDateTime &pRhs) const;

  bool operator>=(const LocalDateTime &pRhs) const;

  bool operator==(const LocalDateTime &pRhs) const;

  bool operator!=(const LocalDateTime &pRhs) const;

  friend std::ostream &operator<<(std::ostream &pOs, const LocalDateTime &pTime);
};


#endif //SUBWAYSIMULATOR_LOCALDATETIME_H
