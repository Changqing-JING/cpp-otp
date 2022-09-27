#include "RsaTokenMock.hpp"

std::string RsaTokenMock::getRandom(std::string userName) {
  if (userName == "joey") {
    return "000000";
  }

  return "";
}