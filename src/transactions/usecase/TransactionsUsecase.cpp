#include "./TransactionsUsecase.hpp"

OperationResult TransactionUsecase::transfer(const std::string &senderUserName, const std::string &receiverUserName, const double &amount,
                                             const std::unique_ptr<IUserDataAccess> &userDataAccess,
                                             const std::unique_ptr<ITransactionDataAccess> &transactionDataAccess) {
    // TODO add diff transaction types useCases polymorphically
    auto sender = userDataAccess->getUserByUserName(senderUserName);
    if(!sender.has_value()){
        return OperationResult{false, 404, "Sender Account doesn't found"};
    }
    auto receiver = userDataAccess->getUserByUserName(receiverUserName);
    if(!receiver.has_value()){
        return OperationResult{.isSuccessful = false,.statusCode = 404,.message="Receiver Account doesn't found"};
    }
    std::unique_ptr<TransferAuthorizer>transferAuth = std::make_unique<TransferAuthorizer>(
            sender.value()->getUserType(),
            receiver.value()->getUserType()
    );
    std::unique_ptr<ITransaction> transactionStrategy = std::make_unique<TransferMoney>(
            std::move(sender.value()->createGateway()),
            std::move(receiver.value()->createGateway()),
            std::move(transferAuth)
    );
    OperationResult response = transactionStrategy->execute(amount);
    if(response.isSuccessful){
        transactionDataAccess->createTransaction(
                Transaction{
                        .sender = sender.value()->getUserProfile().userName,
                        .receiver=receiver.value()->getUserProfile().userName
                }
        );
    }
    return response;
}


std::vector<const Transaction> TransactionUsecase::getAllUserTransactions(
        std::string userName,
        const std::unique_ptr<ITransactionDataAccess>& transactionDataAccess
        ) {
    return transactionDataAccess->getUserTransactions(userName);
}