#ifndef INSTAPAY_IUSER_H
#define INSTAPAY_IUSER_H

#include "./UserProfile.hpp"
#include "../../gateways/IGateway.hpp"

class IUser {
public:
    virtual const UserProfile& getUserProfile() = 0;
    virtual std::unique_ptr<IGateway>createGateway() = 0; // TODO : Move to visitor instead
};


#endif //INSTAPAY_IUSER_H
