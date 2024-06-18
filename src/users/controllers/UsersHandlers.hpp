#ifndef INSTAPAY_USERSHANDLERS_HPP
#define INSTAPAY_USERSHANDLERS_HPP

#include "../../../cpp-httplib/httplib.h"
#include "../dataAccess/IUserDataAccess.hpp"

namespace UsersHandlers {
    void handleSignup(
            const httplib::Request &request,
            httplib::Response &response,
            const std::unique_ptr<IUserDataAccess>& userDataAccess
            );
    void handleGetUserBalance(
            const httplib::Request& request,
            httplib::Response& response,
            const std::unique_ptr<IUserDataAccess>& userDataAccess
            );
}

#endif //INSTAPAY_USERSHANDLERS_HPP
