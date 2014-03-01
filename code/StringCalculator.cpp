#include "StringCalculator.h"

#include <cstdlib> 
#include <boost/algorithm/string.hpp>
#include "NegativeNumbersException.h"

StringCalculator::StringCalculator() {}

StringCalculator::~StringCalculator() {}

int StringCalculator::add(const std::string & numbersSequence) const {
  return add(extractNumbers(numbersSequence));
}

int StringCalculator::add(const std::vector<int> & numbers) const {
  int res = 0;
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    res += numbers[i];
  }
  return res;
}

std::vector<int> StringCalculator::extractNumbers(const std::string & numbersSequence) const {

  std::vector<int> numbers = convertToInts(extractNumbersStrings(numbersSequence));

  //std::vector<int> negatives;
  //for (unsigned int i = 0; i < numbers.size(); ++i) {
  //  if (numbers[i] < 0)
  //    negatives.push_back(numbers[i]);
  //}

  //if (!negatives.empty()) {
  //  throw NegativeNumbersException("");
  //}

  validate(numbers);

  return numbers;
}

std::vector<std::string> StringCalculator::extractNumbersStrings(
  const std::string & numbersSequence) const {

  const std::string defaultDelimiters = ",\n";

  std::string delimiters = defaultDelimiters + 
    extractAdditionalDelimiter(numbersSequence);

  std::vector<std::string> numbersStrings;
  boost::split(numbersStrings, numbersSequence, boost::is_any_of(delimiters));
  return numbersStrings;
}

int StringCalculator::convertToInt(const std::string & str) const {
  return atoi(str.c_str());
}

std::vector<int> StringCalculator::convertToInts(
  const std::vector<std::string> & numbersStrings) const {
  std::vector<int> numbers;
  for (unsigned int i = 0; i < numbersStrings.size(); ++i) {
    numbers.push_back(convertToInt(numbersStrings[i]));
  }
  return numbers;
}

std::string StringCalculator::extractAdditionalDelimiter(const std::string & numbersSequence) const {
  std::string additionalDelimiter = "";

  int endAdditionalDelimiterDefinition = numbersSequence.find("]\n");

  if (endAdditionalDelimiterDefinition != std::string::npos) {
    additionalDelimiter = numbersSequence[endAdditionalDelimiterDefinition - 1];
  }

  return additionalDelimiter;
}

void StringCalculator::validate(const std::vector<int> & numbers) const {
  std::vector<int> negatives = getNegatives(numbers);

  if (!negatives.empty()) {
    throw NegativeNumbersException("");
  }
}

std::vector<int> StringCalculator::getNegatives(const std::vector<int> & numbers) const {
  std::vector<int> negatives;
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    if (numbers[i] < 0)
      negatives.push_back(numbers[i]);
  }
  return negatives;
}