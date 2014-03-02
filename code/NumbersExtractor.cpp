#include "NumbersExtractor.h"

#include "DelimitersExtractor.h"
#include "StringUtils.h"
#include "VectorUtils.h"

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
  return VectorUtils::filter(tokens, StringUtils::isAnInteger);
}

std::vector<int> NumbersExtractor::convertToInts(
  const std::vector<std::string> & numbersStrings) const {
  return VectorUtils::map<int, std::string>(numbersStrings, StringUtils::convertToInt);
}
