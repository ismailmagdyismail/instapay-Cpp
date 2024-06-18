#ifndef INSTAPAY_USERSUSECASE_HPP
#define INSTAPAY_USERSUSECASE_HPP

#include "../../presentation/OperationResult.hpp"
#include "../domain/UserType.hpp"
#include "../dataAccess/IUserDataAccess.hpp"

namespace UsersUsecase {
  OperationResult signup(const std::string& userName,const std::string& phoneNumber,UserType userType );
  std::optional<double> getUserBalance(const std::string& userName,const std::unique_ptr<IUserDataAccess>&userDataAccess);
}
#endif //INSTAPAY_USERSUSECASE_HPP
