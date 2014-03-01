#pragma once

#include <vector>
#include <string>

class NumbersExtractor
{
public:
  NumbersExtractor();
  virtual ~NumbersExtractor();

  std::vector<int> extractFrom(const std::string & numbersSequence) const;

private:
  std::vector<std::string> extractNumbersStrings(const std::string & numbersSequence) const;
  std::vector<std::string> tokenize(const std::string & numbersSequence, 
    const std::string & delimiters) const;
  std::string getDelimiters(const std::string & numbersSequence) const;
  std::vector<std::string> filterOutNotNumericTokens(const std::vector<std::string> & tokens) const;
  std::string extractAdditionalDelimiter(const std::string & numbersSequence) const;
  std::vector<int> convertToInts(const std::vector<std::string> & numbersStrings) const;
  int convertToInt(const std::string & str) const;
  bool isNotNumeric(const std::string & token) const;
};

