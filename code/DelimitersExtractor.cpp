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

  int beginDelimiter = numbersSequence.find("//[") + 3;
  int endDelimiter = numbersSequence.find("]\n");
  int delimiterSize = endDelimiter - beginDelimiter;

  if (endDelimiter != std::string::npos) {
    additionalDelimiter = numbersSequence.substr(beginDelimiter, delimiterSize);
  }

  return additionalDelimiter;
}
