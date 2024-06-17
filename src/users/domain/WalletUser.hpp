#ifndef WALLET_USER_HPP_
#define WALLET_USER_HPP_

#include <iostream>
#include "./UserProfile.hpp"
#include "./IUser.hpp"
#include "../../gateways/Infrastructure/WalletGateways/MockWalletGateway.hpp"

class WalletUser final:public IUser{
public:
    WalletUser(const UserProfile& profile,const std::string& walletProvider):
    userProfile{profile},walletProvider{walletProvider}{}
    const UserProfile& getUserProfile() override{
        return this->userProfile;
    }
    virtual UserType getUserType()override{
        return UserType::WALLET_USER;
    }
    std::unique_ptr<IGateway> createGateway() override{
        return std::make_unique<MockWalletGateway>(this->userProfile.phoneNumber);
    }
    virtual std::unique_ptr<IUser> clone()override{
        return std::make_unique<WalletUser>(*this);
    }
private:
    UserProfile userProfile;
    std::string walletProvider;
};

#endif