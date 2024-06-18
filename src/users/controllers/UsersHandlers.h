#ifndef INSTAPAY_USERSHANDLERS_H
#define INSTAPAY_USERSHANDLERS_H

#include "../../../cpp-httplib/httplib.h"

namespace UsersHandlers {
    void handleSignup(const httplib::Request& request,httplib::Response& response);
}

#endif //INSTAPAY_USERSHANDLERS_H
