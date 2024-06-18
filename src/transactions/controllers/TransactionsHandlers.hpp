#ifndef INSTAPAY_TRANSACTIONSHANDLERS_HPP
#define INSTAPAY_TRANSACTIONSHANDLERS_HPP

#include "../../../cpp-httplib/httplib.h"
#include "../../users/dataAccess/IUserDataAccess.hpp"
#include "../dataAccess/ITransactionDataAccess.hpp"

namespace TransactionsHandlers {
    void handleTransfer(
            const httplib::Request &,
            httplib::Response &response,
            const std::unique_ptr<IUserDataAccess>&userDataAccess,
            const std::unique_ptr<ITransactionDataAccess>&transactionDataAccess
            );
    void handleGetAllTransfers(
            const httplib::Request &,
            httplib::Response &response,
            const std::unique_ptr<ITransactionDataAccess>&transactionDataAccess
            );
}

#endif //INSTAPAY_TRANSACTIONSHANDLERS_HPP
