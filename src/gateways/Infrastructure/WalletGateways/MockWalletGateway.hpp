#ifndef INSTAPAY_MOCKWALLETGATEWAY_HPP
#define INSTAPAY_MOCKWALLETGATEWAY_HPP

#include "../../IGateway.hpp"
#include <iostream>

class MockWalletGateway final : public IGateway{
public:
    MockWalletGateway(const std::string& phoneNumber);
    Response deposit(const double& amount)override;
    Response withdraw(const double& amount)override;
    std::optional<double>getBalance()const override;
private:
    std::string phoneNumber;
};


#endif
