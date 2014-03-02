#include "NumbersExtractor.h"

#include "DelimitersExtractor.h"

#include <cstdlib> 
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/regex.hpp>
#include <map>

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
  return filterOutNotNumericTokens(tokenize(numbersSequence, delimiters));
}

std::vector<std::string> NumbersExtractor::tokenize(const std::string & numbersSequence,
  const std::vector<std::string> & delimiters) const {

  std::vector<std::string> scapedDelimiters = scapeDelimiters(delimiters);

  std::vector<std::string> tokens;

  boost::algorithm::split_regex(
    tokens,
    numbersSequence,
    boost::regex(boost::join(scapedDelimiters, "|")));

  return tokens;
}

std::vector<std::string> NumbersExtractor::filterOutNotNumericTokens(const std::vector<std::string> & tokens) const {
  std::vector<std::string> numericTokens;

  for (unsigned int i = 0; i < tokens.size(); ++i) {
    std::string token = tokens[i];

    if (isNotNumeric(token)) {
      continue;
    }

    numericTokens.push_back(tokens[i]);
  }

  return numericTokens;
}

bool NumbersExtractor::isNotNumeric(const std::string & token) const {
  const boost::regex e("\\s*[+-]?([1-9][0-9]*|0[0-7]*|0[xX][0-9a-fA-F]+)");
  return ! boost::regex_match(token, e);
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

std::string NumbersExtractor::scape(char delimiter) const {
  const std::map<char, std::string> ScapedSpecialCharacters = {
    {'.', "\\."}, {'|', "\\|"}, {'*', "\\*"}, {'?', "\\?"},
    {'+', "\\+"}, {'(', "\\("}, {')', "\\)"}, {'{', "\\{"},
    {'}', "\\}"}, {'[', "\\["}, {']', "\\]"}, {'^', "\\^"},
    {'$', "\\$"}, {'\\', "\\\\"}
  };

  auto it = ScapedSpecialCharacters.find(delimiter);

  if (it == ScapedSpecialCharacters.end())
    return std::string(1, delimiter);

  return it->second;
}

std::string NumbersExtractor::scape(const std::string & delimiter) const {
  std::string scapedDelimiter = "";
  for (unsigned int i = 0; i < delimiter.length(); ++i) {
    scapedDelimiter += scape(delimiter.at(i));
  }
  return scapedDelimiter;
}

std::vector<std::string> NumbersExtractor::scapeDelimiters(const std::vector<std::string> & delimiters) const {
  std::vector<std::string> scapedDelimiters;
  for (unsigned int i = 0; i < delimiters.size(); ++i) {
    scapedDelimiters.push_back(scape(delimiters[i]));
  }
  return scapedDelimiters;
}
