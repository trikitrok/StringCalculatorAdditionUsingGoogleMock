#include <gmock\gmock.h>

#include "..\code\StringCalculator.h"
#include "..\code\NumbersSequenceTokenizer.h"
#include "..\code\NumbersValidator.h"
#include "..\code\NumbersFilter.h"
#include "..\code\NegativeNumbersException.h"
#include "..\code\DelimitersExtractor.h"
#include "..\code\NumbersExtractor.h"

using namespace ::testing;

class AStringCalculator : public Test {
public:
  StringCalculator * stringCalculator;

  void SetUp() {
    std::vector<std::string> DefaultDelimiters{",", "\n"};
    stringCalculator = new StringCalculator(
      new NumbersExtractor(new NumbersSequenceTokenizer(
                                 new DelimitersExtractor(DefaultDelimiters)),
                           new NumbersValidator, 
                           new NumbersFilter));
  }

  void TearDown() {
    delete stringCalculator;
  }
};

TEST_F(AStringCalculator, ReturnsZeroWhenItReceivesAnEmptySequence) {
  ASSERT_THAT(stringCalculator->add(""), Eq(0));
}

TEST_F(AStringCalculator, ReturnsTheOnlyNumberInSequence) {
  ASSERT_THAT(stringCalculator->add("5"), Eq(5));
}

TEST_F(AStringCalculator, AddsNumbersSeparatedByCommasOrNewLineCharacters) {
  ASSERT_THAT(stringCalculator->add("1\n2, 3"), Eq(6));
}

TEST_F(AStringCalculator, AddsNumbersSeparatedByAdditionalDelimiters) {
  ASSERT_THAT(stringCalculator->add("//[@]\n1@2"), Eq(3));
}

TEST_F(AStringCalculator, ThrowsExceptionIfAnyNumberIsNegative) {
  ASSERT_THROW(stringCalculator->add("3, -4, 5, -6"), NegativeNumbersException);
}

TEST_F(AStringCalculator, ThrowsExceptionWithMessageContainingGivenText) {
  try {
    stringCalculator->add("3, -4, 5, -6");
    FAIL();
  } catch (NegativeNumbersException & e) {
    ASSERT_THAT(e.what(), HasSubstr("Negative numbers not allowed"));
  }
}

TEST_F(AStringCalculator, ThrowsExceptionWithMessageContainingTheNegativeNumbers) {
  try {
    stringCalculator->add("3, -4, 5, -6");
    FAIL();
  } catch (NegativeNumbersException & e) {
    ASSERT_THAT(e.what(), HasSubstr("-4, -6"));
  }
}

TEST_F(AStringCalculator, IgnoresAnyNumberGreaterThan1000) {
  ASSERT_THAT(stringCalculator->add("3, 1001, 6"), Eq(9));
}

TEST_F(AStringCalculator, UsesAdditionalDelimitersOfAnyLongitude) {
  ASSERT_THAT(stringCalculator->add("//[***]\n1***2***3"), Eq(6));
}