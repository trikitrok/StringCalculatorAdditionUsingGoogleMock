#pragma once

#include <vector>
#include <string>

class DelimitersExtractor;

class NumbersSequenceTokenizer
{
public:
  NumbersSequenceTokenizer(DelimitersExtractor * delimitersExtractor);
  virtual ~NumbersSequenceTokenizer();

  std::vector<int> extractFrom(const std::string & numbersSequence) const;

private:
  DelimitersExtractor * delimitersExtractor;

  std::vector<std::string> extractNumbersStrings(const std::string & numbersSequence) const;

  std::vector<std::string> filterOutNotNumericTokens(
    const std::vector<std::string> & tokens) const;

  std::vector<int> convertToInts(const std::vector<std::string> & numbersStrings) const;
};

