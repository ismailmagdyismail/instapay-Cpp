#ifndef BANKGATEWAY_HPP_
#define BANKGATEWAY_HPP_

#include <iostream>
#include "../../IGateway.hpp"

class MockBankGateway final : public IGateway{
public:
    MockBankGateway(const std::string& bankAccountNumber);
    Response deposit(const double& amount)override;
    Response withdraw(const double& amount)override;
    std::optional<double> getBalance()const override;

private:
    std::string bankAccountNumber;
};

#endif
