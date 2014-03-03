#pragma once

#include <string>
#include <vector>

class NumbersSequenceTokenizer;
class NumbersValidator;
class NumbersFilter;

class StringCalculator
{
public:
  StringCalculator(NumbersSequenceTokenizer * numbersSequenceTokenizer,
    NumbersValidator * numbersValidator,
    NumbersFilter * numbersFilter);
  virtual ~StringCalculator();

  int add(const std::string & numbersSequence) const;

private:
  NumbersSequenceTokenizer * numbersSequenceTokenizer;
  NumbersValidator * numbersValidator;
  NumbersFilter * numbersFilter;

  int add(const std::vector<int> & numbers) const;

  std::vector<int> extractNumbers(const std::string & numbersSequence) const;
};

