#ifndef INSTAPAY_ITRANSACTION_H
#define INSTAPAY_ITRANSACTION_H

#include "../../presentation/Response.h"

class ITransaction {
public:
    virtual const Response execute(const double& amount)= 0;
    ~ITransaction() = default;
};


#endif
