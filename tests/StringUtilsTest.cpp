#include <gmock\gmock.h>

#include <vector>
#include "../code/StringUtils.h"

using namespace ::testing;

TEST(StringUtils, CanEscapeOneString) {
  EXPECT_THAT(StringUtils::escapeString("*"), Eq("\\*"));
  EXPECT_THAT(StringUtils::escapeString("\\"), Eq("\\\\"));
  EXPECT_THAT(StringUtils::escapeString("||"), Eq("\\|\\|"));
  EXPECT_THAT(StringUtils::escapeString(","), Eq(","));
}

TEST(StringUtils, CanEscapeSeveralStringsEvenThoseUsedInRegularExpressions) {
  EXPECT_THAT(StringUtils::escapeStrings({",", "*", "||", ";", "\\"}),
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

TEST(StringUtils, CanSplitStringsAndJoinThemAgain) {
  std::string str = "1|2|3";
  std::string delimiter = "|";
  EXPECT_THAT(StringUtils::join(StringUtils::split(str, delimiter), delimiter),
    Eq(str));
}
