#include "InMemoryTransactions.hpp"

const std::vector<const Transaction> InMemoryTransactions::getUserTransactions(std::string userName) {
    std::vector<const Transaction>transactions;
    for(auto& entry:this->db){
        if(entry.second.sender == userName){
            transactions.push_back(entry.second);
        }
    }
    return transactions;
}

void InMemoryTransactions::createTransaction(Transaction transaction) {
    transaction.id = InMemoryTransactions::nextId;
    this->db[nextId] = transaction;
    InMemoryTransactions::nextId++;
}

unsigned int InMemoryTransactions::nextId = 1;