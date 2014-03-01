#include <gmock\gmock.h>

#include "..\code\StringCalculator.h"

using namespace ::testing;

class StringCalculatorAddition : public Test {
public:
  StringCalculator stringCalculator;
};

TEST_F(StringCalculatorAddition, ReturnsZeroWhenItReceivesAnEmptySequence) {
  ASSERT_THAT(stringCalculator.add(""), Eq(0));
}

TEST_F(StringCalculatorAddition, ReturnsTheOnlyNumberInSequence) {
  ASSERT_THAT(stringCalculator.add("5"), Eq(5));
}

TEST_F(StringCalculatorAddition, AddsNumbersSeparatedByCommas) {
  ASSERT_THAT(stringCalculator.add("3, 4, 6"), Eq(13));
}

TEST_F(StringCalculatorAddition, AddsNumbersSeparatedByCommasOrNewLineCharacters) {
  ASSERT_THAT(stringCalculator.add("1\n2, 3"), Eq(6));
}