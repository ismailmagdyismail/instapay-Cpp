#ifndef BANK_USER_HPP_
#define BANK_USER_HPP_

#include <iostream>
#include "./UserProfile.hpp"
#include "IUser.hpp"
#include "../gateways/BankGateways/BankGateway.hpp"

class BankUser final :public IUser{
public:
    const UserProfile& getUserProfile()override{
        return this->userProfile;
    }
    std::unique_ptr<IGateway> getGateway()override{
        return std::make_unique<BankGateway>(this->accountNumber);
    }
private:
    UserProfile userProfile;
    std::string bankName;
    std::string accountNumber;
};

#endif