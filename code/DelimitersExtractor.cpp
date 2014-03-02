#include "DelimitersExtractor.h"

#include "StringUtils.h"
#include "VectorUtils.h"

DelimitersExtractor::DelimitersExtractor(
  const std::vector<std::string> & defaultDelimiters) {
  this->defaultDelimiters = defaultDelimiters;
}

DelimitersExtractor::~DelimitersExtractor() 
{}

std::vector<std::string> DelimitersExtractor::extractDelimitersList(
  const std::string & numbersSequence) const {
  
  std::vector<std::string> delimiters(defaultDelimiters);

  if (numbersSequence.empty())
    return delimiters;

  std::string delimitersRegion = extractDelimitersRegion(numbersSequence);

  if (delimitersRegion.empty())
    return delimiters;

  std::vector<std::string> additionalDelimiters = 
    extractAdditionalDelimiters(delimitersRegion);

  VectorUtils::append(delimiters, additionalDelimiters);

  return delimiters;
}

std::vector<std::string> DelimitersExtractor::extractAdditionalDelimiters(
  const std::string & delimitersRegion) const {

  bool moreDelimiters = true;
  std::string restOfDelimitersRegion = std::string(delimitersRegion);

  std::vector<std::string> additionalDelimiters;

  while (moreDelimiters) {
    int beginDelimiter = restOfDelimitersRegion.find("[") + 1;
    int endDelimiter = restOfDelimitersRegion.find("]");

    moreDelimiters = endDelimiter != std::string::npos;

    if (moreDelimiters) {
      additionalDelimiters.push_back(
        StringUtils::extractRegion(restOfDelimitersRegion, beginDelimiter, endDelimiter));

      restOfDelimitersRegion = restOfDelimitersRegion.substr(endDelimiter + 1);
    }
  }

  return additionalDelimiters;
}

std::string DelimitersExtractor::extractDelimitersRegion(
  const std::string & numbersSequence) const {

  int beginDelimitersRegion = numbersSequence.find("//[") + 2;
  int endDelimitersRegion = numbersSequence.find("]\n") + 1;

  std::string delimitersRegion = "";

  if (endDelimitersRegion != std::string::npos) {
    delimitersRegion = StringUtils::extractRegion(
      numbersSequence,
      beginDelimitersRegion,
      endDelimitersRegion);
  }
  return delimitersRegion;
}