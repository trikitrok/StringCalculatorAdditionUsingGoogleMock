#include "StringUtils.h"

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/regex.hpp>
#include <unordered_map>
#include <cstdlib>

std::vector<std::string> StringUtils::split(const std::string & str,
  const std::vector<std::string> & delimiters) {

  std::vector<std::string> tokens;

  boost::algorithm::split_regex(
    tokens,
    str,
    boost::regex(boost::join(escapeDelimiters(delimiters), "|")));

  return tokens;
}

std::string StringUtils::escape(char delimiter) {
  const std::unordered_map<char, std::string> ScapedSpecialCharacters = {
    {'.', "\\."}, {'|', "\\|"}, {'*', "\\*"}, {'?', "\\?"},
    {'+', "\\+"}, {'(', "\\("}, {')', "\\)"}, {'{', "\\{"},
    {'}', "\\}"}, {'[', "\\["}, {']', "\\]"}, {'^', "\\^"},
    {'$', "\\$"}, {'\\', "\\\\"}
  };

  auto it = ScapedSpecialCharacters.find(delimiter);

  if (it == ScapedSpecialCharacters.end())
    return std::string(1, delimiter);

  return it->second;
}

std::string StringUtils::escape(const std::string & delimiter) {
  std::string scapedDelimiter = "";
  for (unsigned int i = 0; i < delimiter.length(); ++i) {
    scapedDelimiter += escape(delimiter.at(i));
  }
  return scapedDelimiter;
}

std::vector<std::string> StringUtils::escapeDelimiters(
  const std::vector<std::string> & delimiters) {
  std::vector<std::string> scapedDelimiters;
  for (unsigned int i = 0; i < delimiters.size(); ++i) {
    scapedDelimiters.push_back(escape(delimiters[i]));
  }
  return scapedDelimiters;
}

bool StringUtils::isAnInteger(const std::string & token) {
  const boost::regex e("\\s*[+-]?([1-9][0-9]*|0[0-7]*|0[xX][0-9a-fA-F]+)");
  return boost::regex_match(token, e);
}

std::string StringUtils::extractRegion(const std::string & str,
  int from, int to) {
  std::string region = "";
  int regionSize = to - from;
  return str.substr(from, regionSize);
}

int StringUtils::convertToInt(const std::string & str) {
  return atoi(str.c_str());
}
