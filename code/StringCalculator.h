#pragma once

#include <string>
#include <vector>

class NumbersExtractor;

class StringCalculator
{
public:
  StringCalculator(NumbersExtractor * numberExtractor);
  virtual ~StringCalculator();

  int add(const std::string & numbersSequence) const;

private:
  NumbersExtractor * numberExtractor;

  int add(const std::vector<int> & numbers) const;

  std::vector<int> extractNumbers(const std::string & numbersSequence) const;
  std::vector<int> ignoreTooBig(const std::vector<int> & numbers) const;
  bool notTooBig(int number) const;
  
  void validate(const std::vector<int> & numbers) const;
  std::vector<int> getNegatives(const std::vector<int> & numbers) const;
  std::string createNegativeNumbersListAsString(const std::vector<int> & negatives) const;
};

