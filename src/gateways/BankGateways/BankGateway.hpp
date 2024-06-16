#ifndef BANKGATEWAY_HPP_
#define BANKGATEWAY_HPP_

#include "../IGateway.hpp"

class BankGateway final : public IGateway{
public:
    BankGateway(const std::string& bankAccountNumber);
    std::optional<std::string> deposit(const double& amount)override;
    std::optional<std::string> withdraw(const double& amount)override;
    std::optional<double> getBalance()const override;

private:
    std::string bankAccountNumber;
};

#endif
