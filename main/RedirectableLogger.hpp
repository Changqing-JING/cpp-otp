#pragma once
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
class RedirectableLogger {

public:
  inline RedirectableLogger() { bufferStream_ = &std::cout; }
  inline RedirectableLogger &operator<<(std::string str) {
    *bufferStream_ << str;
    return *this;
  }

  inline void setOutputStream(std::ostream &stream) noexcept {
    bufferStream_ = &stream;
  }

private:
  std::ostream *bufferStream_;
};