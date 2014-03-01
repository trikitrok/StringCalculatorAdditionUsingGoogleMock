#pragma once

#include <string>
#include <vector>

class NumbersExtractor;
class NumbersValidator;

class StringCalculator
{
public:
  StringCalculator(NumbersExtractor * numberExtractor,
    NumbersValidator * numbersValidator);
  virtual ~StringCalculator();

  int add(const std::string & numbersSequence) const;

private:
  NumbersExtractor * numberExtractor;
  NumbersValidator * numbersValidator;

  int add(const std::vector<int> & numbers) const;

  std::vector<int> extractNumbers(const std::string & numbersSequence) const;
  std::vector<int> ignoreTooBig(const std::vector<int> & numbers) const;
  bool notTooBig(int number) const;
};

