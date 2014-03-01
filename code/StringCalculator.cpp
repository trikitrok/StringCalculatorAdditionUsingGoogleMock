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

    std::vector<std::string> numbersStrings;
    boost::split(numbersStrings, numbersSequence, boost::is_any_of(","));

    std::vector<int> numbers;

    for (unsigned int i = 0; i < numbersStrings.size(); ++i) {
      numbers.push_back(atoi(numbersStrings[i].c_str()));
    }

    int res = 0;

    for (unsigned int i = 0; i < numbers.size(); ++i) {
      res += numbers[i];
    }

    return res;
  }

  return atoi(numbersSequence.c_str());
}
