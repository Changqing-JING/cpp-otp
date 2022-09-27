#ifndef CPP_OTP_AUTHENTICATIONSERVICE_H
#define CPP_OTP_AUTHENTICATIONSERVICE_H

#include "ProfileDao.h"
#include "RedirectableLogger.hpp"
#include "RsaTokenDao.h"
#include <string>

class AuthenticationService {

public:
  static const char *loginFailedMessage;
  AuthenticationService(ProfileDao &profileDao, RsaTokenDao &rsaTokenDao,
                        RedirectableLogger &logger);
  bool isValid(const std::string userName, const std::string password);

private:
  ProfileDao &profileDao_;
  RsaTokenDao &rsaTokenDao_;
  RedirectableLogger &logger_;
};

#endif // CPP_OTP_AUTHENTICATIONSERVICE_H
