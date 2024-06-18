#ifndef INSTAPAY_TRANSACTIONSUSECASE_HPP
#define INSTAPAY_TRANSACTIONSUSECASE_HPP

#include <unordered_map>
#include "../domain/entities/ITransaction.hpp"
#include "../domain/entities/transfers/TransferMoney.hpp"
#include "../../users/dataAccess/IUserDataAccess.hpp"
#include "../dataAccess/ITransactionDataAccess.hpp"

namespace TransactionUsecase {
    OperationResult transfer(
            const std::string& senderUserName,
            const std::string& receiverUserName,
            const double& amount,
            const std::unique_ptr<IUserDataAccess>&userDataAccess,
            const std::unique_ptr<ITransactionDataAccess>&transactionDataAccess
            );
    std::vector<const Transaction> getAllUserTransactions(
            std::string userName,
            const std::unique_ptr<ITransactionDataAccess>& transactionDataAccess
            );
};


#endif
