#include "NumbersExtractor.h"

#include <cstdlib> 
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>

NumbersExtractor::NumbersExtractor() 
{}

NumbersExtractor::~NumbersExtractor() 
{}

std::vector<int> NumbersExtractor::extractFrom(const std::string & numbersSequence) const {
  return convertToInts(extractNumbersStrings(numbersSequence));
}

std::vector<std::string> NumbersExtractor::extractNumbersStrings(
  const std::string & numbersSequence) const {

  std::string delimiters = getDelimiters(numbersSequence);
  return filterOutNotNumericTokens(tokenize(numbersSequence, delimiters));
}

std::vector<std::string> NumbersExtractor::filterOutNotNumericTokens(const std::vector<std::string> & tokens) const {
  std::vector<std::string> notEmptyToken;

  for (unsigned int i = 0; i < tokens.size(); ++i) {
    std::string token = tokens[i];

    if (isNotNumeric(token)) {
      continue;
    }

    notEmptyToken.push_back(tokens[i]);
  }

  return notEmptyToken;
}

bool NumbersExtractor::isNotNumeric(const std::string & token) const {

  const boost::regex e("\\s*[+-]?([1-9][0-9]*|0[0-7]*|0[xX][0-9a-fA-F]+)");
  return !boost::regex_match(token, e);
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

std::vector<std::string> NumbersExtractor::tokenize(const std::string & numbersSequence,
  const std::string & delimiters) const {
  std::vector<std::string> tokens;
  boost::split(tokens, numbersSequence, boost::is_any_of(delimiters));
  return tokens;
}

std::string NumbersExtractor::getDelimiters(const std::string & numbersSequence) const {
  const std::string defaultDelimiters = ",\n";
  return defaultDelimiters + extractAdditionalDelimiter(numbersSequence);
}