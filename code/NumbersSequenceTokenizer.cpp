#include "NumbersSequenceTokenizer.h"

#include "DelimitersExtractor.h"
#include "StringUtils.h"
#include "VectorUtils.h"

NumbersSequenceTokenizer::NumbersSequenceTokenizer(DelimitersExtractor * delimitersExtractor) {
  this->delimitersExtractor = delimitersExtractor;
}

NumbersSequenceTokenizer::~NumbersSequenceTokenizer() {
  delete delimitersExtractor;
}

std::vector<int> NumbersSequenceTokenizer::extractFrom(
  const std::string & numbersSequence) const {
  return convertToInts(extractNumbersStrings(numbersSequence));
}

std::vector<std::string> NumbersSequenceTokenizer::extractNumbersStrings(
  const std::string & numbersSequence) const {
  auto delimiters = delimitersExtractor->extractDelimitersList(numbersSequence);
  return filterOutNotNumericTokens(StringUtils::split(numbersSequence, delimiters));
}

std::vector<std::string> NumbersSequenceTokenizer::filterOutNotNumericTokens(
  const std::vector<std::string> & tokens) const {
  return VectorUtils::filter(tokens, StringUtils::isAnInteger);
}

std::vector<int> NumbersSequenceTokenizer::convertToInts(
  const std::vector<std::string> & numbersStrings) const {
  return VectorUtils::map<int, std::string>(numbersStrings, StringUtils::convertToInt);
}
