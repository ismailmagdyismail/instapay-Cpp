#ifndef INSTAPAY_INMEMORYTRANSACTIONS_HPP
#define INSTAPAY_INMEMORYTRANSACTIONS_HPP


#include "ITransactionDataAccess.hpp"

class InMemoryTransactions final :public ITransactionDataAccess{
public:
    virtual void createTransaction(Transaction transaction)override;
    virtual const std::vector<const Transaction> getUserTransactions(std::string userName) override;
private:
    std::unordered_map<unsigned int,Transaction>db ;
    static unsigned int nextId ;
};


#endif //INSTAPAY_INMEMORYTRANSACTIONS_HPP
