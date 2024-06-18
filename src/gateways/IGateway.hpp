#ifndef IGATEWAY_HPP_
#define IGATEWAY_HPP_

#include <optional>
#include "../presentation/OperationResult.hpp"

class IGateway{
public:
    virtual OperationResult deposit(const double& amount) = 0;
    virtual OperationResult withdraw(const double& amount) = 0;
    virtual std::optional<double> getBalance()const = 0;
    virtual ~IGateway() = default;
};

#endif
