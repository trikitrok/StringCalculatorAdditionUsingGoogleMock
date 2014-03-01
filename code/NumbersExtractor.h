#pragma once

#include <vector>
#include <string>

class NumbersExtractor
{
public:
  NumbersExtractor();
  virtual ~NumbersExtractor();

  std::vector<int> extractNumbers(const std::string & numbersSequence) const;

private:
  std::vector<std::string> extractNumbersStrings(const std::string & numbersSequence) const;
  std::string extractAdditionalDelimiter(const std::string & numbersSequence) const;
  std::vector<int> convertToInts(const std::vector<std::string> & numbersStrings) const;
  int convertToInt(const std::string & str) const;
};

