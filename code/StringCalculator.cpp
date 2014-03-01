#include "StringCalculator.h"

#include <cstdlib> 
#include <boost/algorithm/string.hpp>

StringCalculator::StringCalculator() {}

StringCalculator::~StringCalculator() {}

int StringCalculator::add(const std::string & numbersSequence) {
  return add(extractNumbers(numbersSequence));
}

int StringCalculator::add(const std::vector<int> & numbers) {
  int res = 0;
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    res += numbers[i];
  }
  return res;
}

std::vector<int> StringCalculator::extractNumbers(const std::string & numbersSequence) {
  return convertToInts(extractNumbersStrings(numbersSequence));
}

std::vector<std::string> StringCalculator::extractNumbersStrings(const std::string & numbersSequence) {
  std::vector<std::string> numbersStrings;
  boost::split(numbersStrings, numbersSequence, boost::is_any_of(","));
  return numbersStrings;
}

int StringCalculator::toInt(const std::string & str) {
  return atoi(str.c_str());
}

std::vector<int> StringCalculator::convertToInts(const std::vector<std::string> & numbersStrings) {
  std::vector<int> numbers;
  for (unsigned int i = 0; i < numbersStrings.size(); ++i) {
    numbers.push_back(toInt(numbersStrings[i]));
  }
  return numbers;
}