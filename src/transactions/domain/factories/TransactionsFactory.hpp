#ifndef INSTAPAY_TRANSACTIONSFACTORY_HPP
#define INSTAPAY_TRANSACTIONSFACTORY_HPP

#include <memory>
#include <unordered_map>
#include "../entities/ITransaction.hpp"

namespace TransactionsFactory{
    std::unique_ptr<ITransaction>createTransaction(); //TODO : implement
}



#endif //INSTAPAY_TRANSACTIONSFACTORY_HPP
