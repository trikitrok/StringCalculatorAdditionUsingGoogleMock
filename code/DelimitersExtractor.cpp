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

  std::string additionalDelimiter = extractAdditionalDelimiter(delimitersRegion);

  if (additionalDelimiter != "")
    delimiters.push_back(additionalDelimiter);

  return delimiters;
}

std::string DelimitersExtractor::extractAdditionalDelimiter(
  const std::string & delimitersRegion) const {

  int beginDelimiter = delimitersRegion.find("[") + 1;
  int endDelimiter = delimitersRegion.find("]");
  
  std::string additionalDelimiter = "";
  if (endDelimiter != std::string::npos) {
    additionalDelimiter = StringUtils::extractRegion(
      delimitersRegion,
      beginDelimiter,
      endDelimiter);
  }

  return additionalDelimiter;
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