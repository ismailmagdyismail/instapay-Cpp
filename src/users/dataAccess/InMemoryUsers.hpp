#ifndef INSTAPAY_INMEMORYUSERS_HPP
#define INSTAPAY_INMEMORYUSERS_HPP

#include "IUserDataAccess.hpp"
#include "../domain/WalletUser.hpp"
#include <unordered_map>

class InMemoryUsers final : public IUserDataAccess{
public:
    virtual std::optional<Response> addUser(const std::unique_ptr<IUser>& newUser) override;
    virtual std::optional<IUser*> getUserByPhoneNumber(const std::string& phoneNumber)const override;
    virtual std::optional<IUser*> getUserByUserName(const std::string& userName) const override;
    virtual unsigned int getUsersCount()const override;
    virtual ~InMemoryUsers() = default;
private:
    std::unordered_map<std::string,std::unique_ptr<IUser>>db ;
};


#endif //INSTAPAY_INMEMORYUSERS_HPP
