#include "StringCalculator.h"

#include "NegativeNumbersException.h"
#include "NumbersExtractor.h"

#include <cstdlib> 
#include <boost/algorithm/string.hpp>
#include <sstream>

StringCalculator::StringCalculator(NumbersExtractor * numberExtractor) {
  this->numberExtractor = numberExtractor;
}

StringCalculator::~StringCalculator() {
  delete numberExtractor;
}

int StringCalculator::add(const std::string & numbersSequence) const {
  return add(extractNumbers(numbersSequence));
}

int StringCalculator::add(const std::vector<int> & numbers) const {
  int res = 0;
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    res += numbers[i];
  }
  return res;
}

std::vector<int> StringCalculator::extractNumbers(const std::string & numbersSequence) const {
  std::vector<int> numbers = this->numberExtractor->extractNumbers(numbersSequence);
  validate(numbers);
  return ignoreTooBig(numbers);
}

std::vector<int> StringCalculator::ignoreTooBig(const std::vector<int> & numbers) const {
  std::vector<int> filteredNumbers;
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    if (notTooBig(numbers[i])) {
      filteredNumbers.push_back(numbers[i]);
    }
  }
  return filteredNumbers;
}

bool StringCalculator::notTooBig(int number) const {
  return !(number > 1000);
}

void StringCalculator::validate(const std::vector<int> & numbers) const {
  std::vector<int> negatives = getNegatives(numbers);

  if (!negatives.empty()) {
    throw NegativeNumbersException(createNegativeNumbersListAsString(negatives));
  }
}

std::vector<int> StringCalculator::getNegatives(const std::vector<int> & numbers) const {
  std::vector<int> negatives;
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    if (numbers[i] < 0)
      negatives.push_back(numbers[i]);
  }
  return negatives;
}

std::string StringCalculator::createNegativeNumbersListAsString(const std::vector<int> & negatives) const {

  std::ostringstream numbersList;
  for (unsigned int i = 0; i < negatives.size() - 1; ++i) {
    numbersList << negatives[i] << ", ";
  }
  numbersList << negatives[negatives.size() - 1];

  return numbersList.str();
}