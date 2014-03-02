#pragma once

#include <vector>
#include <string>

class NumbersValidator
{
public:
  NumbersValidator();
  virtual ~NumbersValidator();

  void validate(const std::vector<int> & numbers) const;

private:
  void thowIfAnyNegative(const std::vector<int> & numbers) const;
  std::vector<int> getNegatives(const std::vector<int> & numbers) const;
  std::string createNegativeNumbersListAsString(const std::vector<int> & negatives) const;
};

