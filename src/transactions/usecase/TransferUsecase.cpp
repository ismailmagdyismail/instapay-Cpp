#include "./TransferUseCase.hpp"

Response TransferUseCase::execute(
        const std::string &senderUserName,
        const std::string &receiverUserName,
        const double &amount,
        const std::unique_ptr<IUserDataAccess> &userDataAccess
        ) {
    // TODO add diff transaction types useCases polymorphically
    auto sender = userDataAccess->getUserByUserName(senderUserName);
    if(!sender.has_value()){
        return Response{false,404,"Sender Account doesn't found"};
    }
    auto receiver = userDataAccess->getUserByUserName(receiverUserName);
    if(!receiver.has_value()){
        return Response{false,404,"Receiver Account doesn't found"};
    }
    std::unique_ptr<TransferAuthorizer>transferAuth = std::make_unique<TransferAuthorizer>(
            sender.value()->getUserType(),
            receiver.value()->getUserType()
    );
    std::unique_ptr<ITransaction> transaction = std::make_unique<TransferMoney>(
            std::move(sender.value()->createGateway()),
            std::move(receiver.value()->createGateway()),
            std::move(transferAuth)
    );
    return transaction->execute(amount);
}