#ifndef INSTAPAY_WALLETGATEWAY_HPP
#define INSTAPAY_WALLETGATEWAY_HPP

#include "../IGateway.hpp"

class WalletGateway final : public IGateway{
public:
    WalletGateway(const std::string& phoneNumber);
    std::optional<std::string>deposit(const double& amount)override;
    std::optional<std::string>withdraw(const double& amount)override;
    std::optional<double>getBalance()const override;
private:
    std::string phoneNumber;
};


#endif //INSTAPAY_WALLETGATEWAY_HPP
