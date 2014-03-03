#pragma once

#include <string>
#include <vector>

class NumbersExtractor;

class StringCalculator
{
public:
  StringCalculator(NumbersExtractor * numbersExtractor);
  virtual ~StringCalculator();

  int add(const std::string & numbersSequence) const;

private:
  NumbersExtractor * numbersExtractor;

  int add(const std::vector<int> & numbers) const;

  std::vector<int> extractNumbers(const std::string & numbersSequence) const;
};

