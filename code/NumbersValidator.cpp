#include "NumbersValidator.h"

#include "NegativeNumbersException.h"

#include <sstream>

NumbersValidator::NumbersValidator() 
{}

NumbersValidator::~NumbersValidator() 
{}

void NumbersValidator::validate(const std::vector<int> & numbers) const {
  std::vector<int> negatives = getNegatives(numbers);

  if (!negatives.empty()) {
    throw NegativeNumbersException(createNegativeNumbersListAsString(negatives));
  }
}

std::vector<int> NumbersValidator::getNegatives(const std::vector<int> & numbers) const {
  std::vector<int> negatives;
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    if (numbers[i] < 0)
      negatives.push_back(numbers[i]);
  }
  return negatives;
}

std::string NumbersValidator::createNegativeNumbersListAsString(const std::vector<int> & negatives) const {

  std::ostringstream numbersList;
  for (unsigned int i = 0; i < negatives.size() - 1; ++i) {
    numbersList << negatives[i] << ", ";
  }
  numbersList << negatives[negatives.size() - 1];

  return numbersList.str();
}