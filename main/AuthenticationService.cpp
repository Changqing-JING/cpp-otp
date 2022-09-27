//
// Created by Joseph Yao on 2018/7/31.
//

#include "AuthenticationService.h"
#include "ProfileDao.h"
#include "RedirectableLogger.hpp"
#include "RsaTokenDao.h"
#include <string>

const char *AuthenticationService::loginFailedMessage = "login failed";

AuthenticationService::AuthenticationService(ProfileDao &profileDao,
                                             RsaTokenDao &rsaTokenDao,
                                             RedirectableLogger &logger)
    : profileDao_(profileDao), rsaTokenDao_(rsaTokenDao), logger_(logger) {}

bool AuthenticationService::isValid(const std::string userName,
                                    const std::string password) {
  // 根據 account 取得自訂密碼
  auto passwordFromDao = profileDao_.getPassword(userName);

  // 根據 account 取得 RSA token 目前的亂數
  auto randomCode = rsaTokenDao_.getRandom(userName);

  // 驗證傳入的 password 是否等於自訂密碼 + RSA token亂數
  auto validPassword = passwordFromDao + randomCode;
  auto isValid = password == validPassword;

  if (isValid) {
    return true;
  } else {
    logger_ << loginFailedMessage;
    return false;
  }
}
