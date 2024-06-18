#ifndef INSTAPAY_ITRANSACTIONDATAACCESS_HPP
#define INSTAPAY_ITRANSACTIONDATAACCESS_HPP

#include <iostream>
#include <vector>
#include "../domain/entities/transfers/Transaction.hpp"
#include "../../presentation/Response.hpp"

class ITransactionDataAccess {
public:
    virtual void createTransaction(Transaction transaction) = 0;
    virtual const std::vector<const Transaction> getUserTransactions(std::string userName) = 0;
    virtual ~ITransactionDataAccess() = default;
};


#endif //INSTAPAY_ITRANSACTIONDATAACCESS_HPP
