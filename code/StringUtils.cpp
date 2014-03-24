#include "StringUtils.h"

#include <unordered_map>
#include <regex>
#include <sstream>

std::string StringUtils::join(const std::vector<std::string> & tokens, const std::string & delimiter) {
  std::stringstream stream;
  stream << tokens.front();
  std::for_each(
    begin(tokens) + 1,
    end(tokens),
    [&](const std::string &elem) { stream << delimiter << elem; }
  );
  return stream.str();
}

std::vector<std::string> StringUtils::split(const std::string & str,
  const std::vector<std::string> & delimiters) {

  std::regex rgx(join(escapeDelimiters(delimiters), "|"));

  std::sregex_token_iterator first{str.begin(), str.end(), rgx, -1};
  std::sregex_token_iterator last;

  return {first, last};
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
  const std::regex e("\\s*[+-]?([1-9][0-9]*|0[0-7]*|0[xX][0-9a-fA-F]+)");
  return std::regex_match(token, e);
}

std::string StringUtils::extractRegion(const std::string & str,
  int from, int to) {
  std::string region = "";
  int regionSize = to - from;
  return str.substr(from, regionSize);
}

int StringUtils::convertToInt(const std::string & str) {
  std::string::size_type sz;
  return std::stoi(str, &sz);
}
