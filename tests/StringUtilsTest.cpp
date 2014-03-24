#include <gmock\gmock.h>

#include <vector>
#include "../code/StringUtils.h"

using namespace ::testing;

TEST(StringUtils, CanEscapeOneDelimeter) {
  EXPECT_THAT(StringUtils::escape("*"), Eq("\\*"));
  EXPECT_THAT(StringUtils::escape("\\"), Eq("\\\\"));
  EXPECT_THAT(StringUtils::escape("||"), Eq("\\|\\|"));
  EXPECT_THAT(StringUtils::escape(","), Eq(","));
}

TEST(StringUtils, CanEscapeSeveralDelimitersEvenThoseUsedInRegularExpressions) {

  std::vector<std::string> delimiters = {",", "*", "||", ";", "\\"};

  EXPECT_THAT(StringUtils::escapeDelimiters(delimiters),
    ElementsAre(",", "\\*", "\\|\\|", ";", "\\\\"));
}

TEST(StringUtils, CanSplitUsingMultipleTokens) {

  std::vector<std::string> delimiters = {",", "*", "??"};

  EXPECT_THAT(StringUtils::split("1*2??3,4", delimiters),
    ElementsAre("1", "2", "3", "4"));
}

TEST(StringUtils, CanTellIfAGivenStringRepresentsAnInteger) {
  EXPECT_TRUE(StringUtils::isAnInteger("1"));
  EXPECT_FALSE(StringUtils::isAnInteger("15 7 8"));
  EXPECT_FALSE(StringUtils::isAnInteger("1.5"));
  EXPECT_FALSE(StringUtils::isAnInteger("!15"));
}

TEST(StringUtils, CanJoinAVectorOfStrings) {
  EXPECT_THAT(StringUtils::join({"1", "2", "3"}, "|"), Eq("1|2|3"));
  EXPECT_THAT(StringUtils::join({"1", "2", "3"}, " "), Eq("1 2 3"));
  EXPECT_THAT(StringUtils::join({"1", "2", "3"}, ", "), Eq("1, 2, 3"));
  EXPECT_THAT(StringUtils::join({"1", "2", "3"}, ""), Eq("123"));
}
