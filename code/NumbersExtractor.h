#pragma once

#include <vector>
#include <string>

class NumbersSequenceTokenizer;
class NumbersValidator;
class NumbersFilter;

class NumbersExtractor
{
public:
  NumbersExtractor(
    NumbersSequenceTokenizer * numbersSequenceTokenizer,
    NumbersValidator * numbersValidator,
    NumbersFilter * numbersFilter);
  virtual ~NumbersExtractor();

  std::vector<int> extractNumbers(const std::string & numbersSequence) const;

private:
  NumbersSequenceTokenizer * numbersSequenceTokenizer;
  NumbersValidator * numbersValidator;
  NumbersFilter * numbersFilter;
};

