#include <gmock\gmock.h>

#include "..\code\StringCalculator.h"

using namespace ::testing;

TEST(StringCalculatorAddition, ReturnsZeroWhenItReceivesAnEmptySequence) {
  StringCalculator stringCalculator;

  ASSERT_THAT(stringCalculator.add(""), Eq(0));
}

TEST(StringCalculatorAddition, ReturnsTheOnlyNumberInSequence) {
  StringCalculator stringCalculator;

  ASSERT_THAT(stringCalculator.add("5"), Eq(5));
}

TEST(StringCalculatorAddition, AddsNumbersSeparatedByCommas) {
  StringCalculator stringCalculator;

  ASSERT_THAT(stringCalculator.add("2, 4"), Eq(6));
  ASSERT_THAT(stringCalculator.add("3, 4, 6"), Eq(13));
}