#ifndef WALLET_USER_HPP_
#define WALLET_USER_HPP_

#include <iostream>
#include "./UserProfile.hpp"
#include "./IUser.hpp"
#include "../../gateways/Infrastructure/WalletGateways/MockWalletGateway.hpp"

class WalletUser final:public IUser{
public:
    const UserProfile& getUserProfile() override{
        return this->userProfile;
    }
    std::unique_ptr<IGateway> createGateway() override{
        return std::make_unique<MockWalletGateway>(this->userProfile.phoneNumber);
    }
private:
    UserProfile userProfile;
    std::string walletProvider;
};

#endif