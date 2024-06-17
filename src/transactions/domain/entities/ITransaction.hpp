#ifndef INSTAPAY_ITRANSACTION_H
#define INSTAPAY_ITRANSACTION_H


#include "../../../presentation/Response.hpp"

class ITransaction {
public:
    virtual Response execute(const double& amount) = 0;
    virtual ~ITransaction() = default;
};


#endif
