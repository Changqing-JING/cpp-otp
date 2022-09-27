#include "main/AuthenticationService.h"
#include "gtest/gtest.h"
#include <sstream>
#include "ProfileMock.hpp"
#include "RsaTokenMock.hpp"

namespace {

struct UserAccount {
  std::string username;
  std::string password;
};

TEST(AuthenticationService, IsValid) {
  ProfileMock profileMock;
  RsaTokenMock rsaTokenMock;
  RedirectableLogger logger;
  std::stringstream sstream;
  logger.setOutputStream(sstream);
  AuthenticationService target(profileMock, rsaTokenMock, logger);

  UserAccount correctUser{"joey", "91000000"};
  bool loginSuccess = target.isValid(correctUser.username, correctUser.password);

  ASSERT_TRUE(loginSuccess);

  loginSuccess = target.isValid(correctUser.username, correctUser.password + "0");

  ASSERT_FALSE(loginSuccess);

  std::string const outputMessage = sstream.str();

  ASSERT_TRUE(outputMessage.find(AuthenticationService::loginFailedMessage) != std::string::npos);
}

} // namespace