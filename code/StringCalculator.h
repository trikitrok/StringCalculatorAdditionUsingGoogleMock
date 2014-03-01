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
};

