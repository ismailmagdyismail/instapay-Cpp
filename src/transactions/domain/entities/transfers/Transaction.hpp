#ifndef INSTAPAY_TRANSACTION_HPP
#define INSTAPAY_TRANSACTION_HPP

#include <iostream>

struct Transaction {
    unsigned int id;
    std::string sender;
    std::string receiver;
};


#endif //INSTAPAY_TRANSACTION_HPP
