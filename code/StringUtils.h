#pragma once

#include <string>
#include <vector>

namespace StringUtils
{
  std::vector<std::string> split(const std::string & str,
    const std::vector<std::string> & delimiters);
  
  std::string escape(char delimiter);
  
  std::string escape(const std::string & delimiter);
  
  std::vector<std::string> escapeDelimiters(
    const std::vector<std::string> & delimiters);

  bool isAnInteger(const std::string & token);

  std::string extractRegion(const std::string & str,
    int from, int to);

  int convertToInt(const std::string & str);

  std::string join(const std::vector<std::string> & tokens, const std::string & delimiter);
};


