#include "NumbersExtractor.h"

#include "DelimitersExtractor.h"
#include "StringUtils.h"

#include <algorithm>

NumbersExtractor::NumbersExtractor(DelimitersExtractor * delimitersExtractor) {
  this->delimitersExtractor = delimitersExtractor;
}

NumbersExtractor::~NumbersExtractor() {
  delete delimitersExtractor;
}

std::vector<int> NumbersExtractor::extractFrom(const std::string & numbersSequence) const {
  return convertToInts(extractNumbersStrings(numbersSequence));
}

std::vector<std::string> NumbersExtractor::extractNumbersStrings(
  const std::string & numbersSequence) const {
  std::vector<std::string> delimiters = delimitersExtractor->extractDelimitersList(numbersSequence);
  return filterOutNotNumericTokens(StringUtils::split(numbersSequence, delimiters));
}

std::vector<std::string> NumbersExtractor::filterOutNotNumericTokens(const std::vector<std::string> & tokens) const {
  std::vector<std::string> numericTokens;

  std::copy_if(tokens.begin(), tokens.end(),
    std::back_inserter(numericTokens),
    StringUtils::isAnInteger);

  return numericTokens;
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

