#include <gmock\gmock.h>

#include "..\code\StringCalculator.h"
#include "..\code\NumbersExtractor.h"
#include "..\code\NegativeNumbersException.h"

using namespace ::testing;

class StringCalculatorAddition : public Test {
public:
  StringCalculator * stringCalculator;

  void SetUp() {
    stringCalculator = new StringCalculator(new NumbersExtractor);
  }

  void TearDown() {
    delete stringCalculator;
  }
};

TEST_F(StringCalculatorAddition, ReturnsZeroWhenItReceivesAnEmptySequence) {
  ASSERT_THAT(stringCalculator->add(""), Eq(0));
}

TEST_F(StringCalculatorAddition, ReturnsTheOnlyNumberInSequence) {
  ASSERT_THAT(stringCalculator->add("5"), Eq(5));
}

TEST_F(StringCalculatorAddition, AddsNumbersSeparatedByCommas) {
  ASSERT_THAT(stringCalculator->add("3, 4, 6"), Eq(13));
}

TEST_F(StringCalculatorAddition, AddsNumbersSeparatedByCommasOrNewLineCharacters) {
  ASSERT_THAT(stringCalculator->add("1\n2, 3"), Eq(6));
}

TEST_F(StringCalculatorAddition, AddsNumbersSeparatedByAdditionalDelimiters) {
  ASSERT_THAT(stringCalculator->add("//[;]\n1;2"), Eq(3));
  ASSERT_THAT(stringCalculator->add("//[@]\n1@2"), Eq(3));
}

TEST_F(StringCalculatorAddition, ThrowsExceptionIfAnyNumberIsNegative) {
  try {
    stringCalculator->add("3, -4, 5, -6");
    FAIL();
  } catch (NegativeNumbersException & e) {
    ASSERT_THAT(e.what(), HasSubstr("Negative numbers not allowed"));
    ASSERT_THAT(e.what(), HasSubstr("-4, -6"));
  }
}

TEST_F(StringCalculatorAddition, IgnoreAnyNumberGreaterThan1000) {
  ASSERT_THAT(stringCalculator->add("3, 1001, 6"), Eq(9));
}