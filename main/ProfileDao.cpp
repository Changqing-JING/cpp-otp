#include "ProfileDao.h"
#include "Context.h"

std::string ProfileDao::getPassword(const std::string userName) {
  static Context const context;
  static_cast<void>(context);
  return Context::getPassword(userName);
}
