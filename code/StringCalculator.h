#pragma once

#include <string>
#include <vector>

class StringCalculator
{
public:
  StringCalculator();
  virtual ~StringCalculator();

  int add(const std::string & numbersSequence) const;

private:
  int add(const std::vector<int> & numbers) const;

  std::vector<int> extractNumbers(const std::string & numbersSequence) const;
  std::vector<int> ignoreTooBig(const std::vector<int> & numbers) const;
  std::vector<std::string> extractNumbersStrings(const std::string & numbersSequence) const;
  std::string extractAdditionalDelimiter(const std::string & numbersSequence) const;
  std::vector<int> convertToInts(const std::vector<std::string> & numbersStrings) const;
  int convertToInt(const std::string & str) const;
  void validate(const std::vector<int> & numbers) const;
  std::vector<int> getNegatives(const std::vector<int> & numbers) const;
  std::string createNegativeNumbersListAsString(const std::vector<int> & negatives) const;
};

