#ifndef IGATEWAY_HPP_
#define IGATEWAY_HPP_

#include <optional>
#include "../presentation/Response.hpp"

class IGateway{
public:
    virtual Response deposit(const double& amount) = 0;
    virtual Response withdraw(const double& amount) = 0;
    virtual std::optional<double> getBalance()const = 0;
    virtual ~IGateway() = default;
};

#endif
