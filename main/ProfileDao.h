#ifndef CPP_OTP_PROFILEDAO_H
#define CPP_OTP_PROFILEDAO_H

#include "Context.h"
#include <string>

class ProfileDao {

public:
  ~ProfileDao() noexcept = default;
  virtual std::string getPassword(std::string userName);
};

#endif // CPP_OTP_PROFILEDAO_H
