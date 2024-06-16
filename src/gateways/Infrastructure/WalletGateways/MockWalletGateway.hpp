#ifndef INSTAPAY_MOCKWALLETGATEWAY_HPP
#define INSTAPAY_MOCKWALLETGATEWAY_HPP

#include "../../IGateway.hpp"
#include <iostream>

class MockWalletGateway final : public IGateway{
public:
    MockWalletGateway(const std::string& phoneNumber);
    std::optional<std::string>deposit(const double& amount)override;
    std::optional<std::string>withdraw(const double& amount)override;
    std::optional<double>getBalance()const override;
private:
    std::string phoneNumber;
};


#endif
