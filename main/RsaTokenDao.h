#ifndef CPP_OTP_RSATOKENDAO_H
#define CPP_OTP_RSATOKENDAO_H

#include <string>

class RsaTokenDao {

public:
  ~RsaTokenDao() noexcept = default;
  virtual std::string getRandom(std::string userName);
};

#endif // CPP_OTP_RSATOKENDAO_H
