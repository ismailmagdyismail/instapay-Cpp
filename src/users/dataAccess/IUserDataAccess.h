#ifndef INSTAPAY_IUSERDATAACCESS_H
#define INSTAPAY_IUSERDATAACCESS_H

#include <optional>
#include "../../Presentation/Response.h"
#include "../domain/IUser.hpp"

class IUserDataAccess {
public:
    virtual std::optional<Response> addUser(const std::unique_ptr<IUser>& newUser) = 0;
    virtual std::optional<std::unique_ptr<IUser>> getUserByPhoneNumber(const std::string& phoneNumber) = 0;
    virtual std::optional<std::unique_ptr<IUser>> getUserByUserName(const std::string& userName) = 0;
    virtual unsigned int getUsersCount() = 0 ;
    virtual ~IUserDataAccess() = default;
};


#endif //INSTAPAY_IUSERDATAACCESS_H
