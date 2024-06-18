#include "UsersUsecase.hpp"

std::optional<double> UsersUsecase::getUserBalance(
        const std::string &userName,
        const std::unique_ptr<IUserDataAccess>& userDataAccess
        ){
    auto user =userDataAccess->getUserByUserName(userName);
    if(user.has_value()){
        return user.value()->createGateway()->getBalance();
    }
    return {};
}