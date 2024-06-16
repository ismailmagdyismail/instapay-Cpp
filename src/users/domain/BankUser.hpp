#ifndef BANK_USER_HPP_
#define BANK_USER_HPP_

#include <iostream>
#include "./UserProfile.hpp"
#include "IUser.hpp"
#include "../../gateways/Infrastructure/BankGateways/MockBankGateway.hpp"

class BankUser final :public IUser{
public:
    const UserProfile& getUserProfile()override{
        return this->userProfile;
    }
    std::unique_ptr<IGateway> createGateway()override{
        return std::make_unique<MockBankGateway>(this->accountNumber);
    }
private:
    UserProfile userProfile;
    std::string bankName;
    std::string accountNumber;
};

#endif