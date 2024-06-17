#ifndef INSTAPAY_INMEMORYUSERS_H
#define INSTAPAY_INMEMORYUSERS_H


#include "IUserDataAccess.h"
#include <unordered_map>

class InMemoryUsers final : public IUserDataAccess{
public:
    virtual std::optional<Response> addUser(const std::unique_ptr<IUser>& newUser) override;
    virtual std::optional<std::unique_ptr<IUser>> getUserByPhoneNumber(const std::string& phoneNumber) override;
    virtual std::optional<std::unique_ptr<IUser>> getUserByUserName(const std::string& userName) override;
    virtual unsigned int getUsersCount()override;
    virtual ~InMemoryUsers() = default;
private:
    std::unordered_map<std::string,std::unique_ptr<IUser>>db;
};


#endif //INSTAPAY_INMEMORYUSERS_H
