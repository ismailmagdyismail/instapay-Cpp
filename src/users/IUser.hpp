#ifndef INSTAPAY_IUSER_H
#define INSTAPAY_IUSER_H

#include "./UserProfile.hpp"
#include "../gateways/IGateway.hpp"

class IUser {
public:
    virtual const UserProfile& getUserProfile() = 0;
    virtual std::unique_ptr<IGateway>getGateway() = 0;
};


#endif //INSTAPAY_IUSER_H
