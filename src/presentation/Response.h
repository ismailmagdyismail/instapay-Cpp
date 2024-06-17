#ifndef INSTAPAY_RESPONSE_H
#define INSTAPAY_RESPONSE_H

#include <iostream>

struct Response {
    bool isSuccessful;
    unsigned int statusCode;
    std::string message;
};


#endif //INSTAPAY_RESPONSE_H
