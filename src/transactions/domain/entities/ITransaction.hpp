#ifndef INSTAPAY_ITRANSACTION_H
#define INSTAPAY_ITRANSACTION_H

#include "../../../presentation/OperationResult.hpp"

class ITransaction {
public:
    virtual OperationResult execute(const double& amount) = 0;
    virtual ~ITransaction() = default;
};


#endif
