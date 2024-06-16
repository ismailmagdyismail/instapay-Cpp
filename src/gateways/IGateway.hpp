#ifndef IGATEWAY_HPP_
#define IGATEWAY_HPP_

#include <optional>

class IGateway{
public:
    virtual std::optional<std::string> deposit(const double& amount) = 0;
    virtual std::optional<std::string> withdraw(const double& amount) = 0;
    virtual std::optional<double> getBalance()const = 0;
    virtual ~IGateway() = default;
};

#endif
