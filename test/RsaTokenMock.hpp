#pragma once
#include "main/RsaTokenDao.h"

class RsaTokenMock : public RsaTokenDao {
public:
  std::string getRandom(std::string userName) override;
};