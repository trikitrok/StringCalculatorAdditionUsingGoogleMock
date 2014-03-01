#include "DelimitersExtractor.h"

DelimitersExtractor::DelimitersExtractor(const std::vector<std::string> & defaultDelimiters) {
  this->defaultDelimiters = defaultDelimiters;
}

DelimitersExtractor::~DelimitersExtractor() 
{}

std::vector<std::string> DelimitersExtractor::extractDelimitersList(const std::string & numbersSequence) const {
  
  std::vector<std::string> delimiters(defaultDelimiters);

  std::string additionalDelimiter = extractAdditionalDelimiter(numbersSequence);

  if (additionalDelimiter != "")
    delimiters.push_back(additionalDelimiter);

  return delimiters;
}

std::string DelimitersExtractor::extractAdditionalDelimiter(
  const std::string & numbersSequence) const {
  std::string additionalDelimiter = "";

  int endAdditionalDelimiterDefinition = numbersSequence.find("]\n");

  if (endAdditionalDelimiterDefinition != std::string::npos) {
    additionalDelimiter = numbersSequence[endAdditionalDelimiterDefinition - 1];
  }

  return additionalDelimiter;
}
