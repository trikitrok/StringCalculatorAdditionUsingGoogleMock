#include "DelimitersExtractor.h"

DelimitersExtractor::DelimitersExtractor(const std::string & defaultDelimiters) {
  this->defaultDelimiters = defaultDelimiters;
}

DelimitersExtractor::~DelimitersExtractor() 
{}

std::string DelimitersExtractor::extractDelimiters(const std::string & numbersSequence) const {
  //const std::string defaultDelimiters = ",\n";
  return defaultDelimiters + extractAdditionalDelimiter(numbersSequence);
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