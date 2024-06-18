#ifndef INSTAPAY_OPERATIONRESULT_HPP
#define INSTAPAY_OPERATIONRESULT_HPP

#include <iostream>

struct OperationResult {
    bool isSuccessful;
    unsigned int statusCode;
    std::string message;
};


#endif //INSTAPAY_OPERATIONRESULT_HPP
