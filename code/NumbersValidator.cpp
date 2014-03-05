#include "NumbersValidator.h"

#include "NegativeNumbersException.h"
#include "VectorUtils.h"

#include <sstream>

NumbersValidator::NumbersValidator() 
{}

NumbersValidator::~NumbersValidator() 
{}

void NumbersValidator::validate(const std::vector<int> & numbers) const {
  thowIfAnyNegative(numbers);
}

void NumbersValidator::thowIfAnyNegative(const std::vector<int> & numbers) const {
  auto negatives = getNegatives(numbers);

  if (!negatives.empty()) {
    throw NegativeNumbersException(createNegativeNumbersListAsString(negatives));
  }
}

std::vector<int> NumbersValidator::getNegatives(const std::vector<int> & numbers) const {
  return VectorUtils::filter(numbers, [](int number) { return number < 0; });
}

std::string NumbersValidator::createNegativeNumbersListAsString(
  const std::vector<int> & negatives) const {

  std::ostringstream numbersList;
  for (unsigned int i = 0; i < negatives.size() - 1; ++i) {
    numbersList << negatives[i] << ", ";
  }
  numbersList << negatives[negatives.size() - 1];

  return numbersList.str();
}