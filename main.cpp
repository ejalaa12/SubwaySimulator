#include <iostream>
#include <boost/date_time.hpp>


int main() {
  std::string hello = "Hello world";
  std::cout << hello << std::endl;

  boost::gregorian::date d {2016, 3, 21};
  std::cout << d << std::endl;
  boost::gregorian::date d2 {2017, 2, 19};
  std::cout << d2 << " - " << d << " = " << d2-d << std::endl;

  return 0;
}