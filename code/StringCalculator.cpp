#include "StringCalculator.h"

#include <cstdlib> 
#include <boost/algorithm/string.hpp>
#include <vector>

StringCalculator::StringCalculator() {}

StringCalculator::~StringCalculator() {}

int StringCalculator::add(const std::string & numbersSequence) {
  if (numbersSequence.empty())
    return 0;

  if (numbersSequence.find(",") != std::string::npos) {

    std::vector<std::string> numbers;
    boost::split(numbers, numbersSequence, boost::is_any_of(","));

    int res = 0;

    for (unsigned int i = 0; i < numbers.size(); ++i) {
      res += atoi(numbers[i].c_str());
    }

    return res;
  }

  return atoi(numbersSequence.c_str());
}
