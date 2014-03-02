#include "DelimitersExtractor.h"

#include "StringUtils.h"

DelimitersExtractor::DelimitersExtractor(const std::vector<std::string> & defaultDelimiters) {
  this->defaultDelimiters = defaultDelimiters;
}

DelimitersExtractor::~DelimitersExtractor() 
{}

std::vector<std::string> DelimitersExtractor::extractDelimitersList(const std::string & numbersSequence) const {
  
  std::vector<std::string> delimiters(defaultDelimiters);

  if (numbersSequence.empty())
    return delimiters;

  std::string delimitersRegion = extractDelimitersRegion(numbersSequence);

  if (delimitersRegion.empty())
    return delimiters;

  std::vector<std::string> additionalDelimiters = extractAdditionalDelimiters(delimitersRegion);

  delimiters.insert(delimiters.end(), 
    additionalDelimiters.begin(), 
    additionalDelimiters.end());

  return delimiters;
}

std::vector<std::string> DelimitersExtractor::extractAdditionalDelimiters(
  const std::string & delimitersRegion) const {

  std::vector<std::string> additionalDelimiters;

  int beginDelimiter = delimitersRegion.find("[") + 1;
  int endDelimiter = delimitersRegion.find("]");
    
  if (endDelimiter != std::string::npos) {
    additionalDelimiters.push_back(StringUtils::extractRegion(
      delimitersRegion,
      beginDelimiter,
      endDelimiter));
  }

  std::string delimitersRegionRest = delimitersRegion.substr(endDelimiter + 1);

  beginDelimiter = delimitersRegionRest.find("[") + 1;
  endDelimiter = delimitersRegionRest.find("]");

  if (endDelimiter != std::string::npos) {
    additionalDelimiters.push_back(StringUtils::extractRegion(
      delimitersRegionRest,
      beginDelimiter,
      endDelimiter));
  }

  return additionalDelimiters;
}

std::string DelimitersExtractor::extractDelimitersRegion(const std::string & numbersSequence) const {
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