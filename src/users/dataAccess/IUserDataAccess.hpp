#ifndef INSTAPAY_IUSERDATAACCESS_HPP
#define INSTAPAY_IUSERDATAACCESS_HPP

#include <optional>
#include "../domain/IUser.hpp"

class IUserDataAccess {
public:
    virtual std::optional<Response> addUser(const std::unique_ptr<IUser>& newUser) = 0;
    virtual std::optional<IUser*> getUserByPhoneNumber(const std::string& phoneNumber) const = 0 ;
    virtual std::optional<IUser*> getUserByUserName(const std::string& userName)const = 0;
    virtual unsigned int getUsersCount() const = 0 ;
    virtual ~IUserDataAccess() = default;
};


#endif //INSTAPAY_IUSERDATAACCESS_HPP
