#pragma once

#include <string>
#include <vector>

class StringCalculator
{
public:
  StringCalculator();
  virtual ~StringCalculator();

  int add(const std::string & numbersSequence);

private:
  int add(const std::vector<int> & numbers);

  std::vector<int> extractNumbers(const std::string & numbersSequence);
  std::vector<std::string> extractNumbersStrings(const std::string & numbersSequence);
  std::vector<int> convertToInts(const std::vector<std::string> & numbersStrings);
  int toInt(const std::string & str);
};

