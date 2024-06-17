#ifndef INSTAPAY_RESPONSE_HPP
#define INSTAPAY_RESPONSE_HPP

#include <iostream>

struct Response {
    bool isSuccessful;
    unsigned int statusCode;
    std::string message;
};


#endif //INSTAPAY_RESPONSE_HPP
