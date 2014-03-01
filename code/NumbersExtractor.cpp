#include "NumbersExtractor.h"

#include <cstdlib> 
#include <boost/algorithm/string.hpp>

NumbersExtractor::NumbersExtractor() 
{}

NumbersExtractor::~NumbersExtractor() 
{}

std::vector<int> NumbersExtractor::extractNumbers(const std::string & numbersSequence) const {
  return convertToInts(extractNumbersStrings(numbersSequence));
}

std::vector<std::string> NumbersExtractor::extractNumbersStrings(
  const std::string & numbersSequence) const {

  const std::string defaultDelimiters = ",\n";

  std::string delimiters = defaultDelimiters +
    extractAdditionalDelimiter(numbersSequence);

  std::vector<std::string> numbersStrings;
  boost::split(numbersStrings, numbersSequence, boost::is_any_of(delimiters));
  return numbersStrings;
}

int NumbersExtractor::convertToInt(const std::string & str) const {
  return atoi(str.c_str());
}

std::vector<int> NumbersExtractor::convertToInts(
  const std::vector<std::string> & numbersStrings) const {
  std::vector<int> numbers;
  for (unsigned int i = 0; i < numbersStrings.size(); ++i) {
    numbers.push_back(convertToInt(numbersStrings[i]));
  }
  return numbers;
}

std::string NumbersExtractor::extractAdditionalDelimiter(
  const std::string & numbersSequence) const {
  std::string additionalDelimiter = "";

  int endAdditionalDelimiterDefinition = numbersSequence.find("]\n");

  if (endAdditionalDelimiterDefinition != std::string::npos) {
    additionalDelimiter = numbersSequence[endAdditionalDelimiterDefinition - 1];
  }

  return additionalDelimiter;
}