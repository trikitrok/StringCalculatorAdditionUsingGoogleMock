#pragma once

#include <vector>
#include <string>

class DelimitersExtractor;

class NumbersExtractor
{
public:
  NumbersExtractor(DelimitersExtractor * delimitersExtractor);
  virtual ~NumbersExtractor();

  std::vector<int> extractFrom(const std::string & numbersSequence) const;

private:
  DelimitersExtractor * delimitersExtractor;

  std::vector<std::string> extractNumbersStrings(const std::string & numbersSequence) const;
  std::vector<std::string> filterOutNotNumericTokens(const std::vector<std::string> & tokens) const;
  std::vector<int> convertToInts(const std::vector<std::string> & numbersStrings) const;
  int convertToInt(const std::string & str) const;
};

