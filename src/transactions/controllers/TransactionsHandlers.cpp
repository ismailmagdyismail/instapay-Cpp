#include "TransactionsHandlers.hpp"
#include "../usecase/TransactionsUsecase.hpp"


void TransactionsHandlers::handleTransfer(
        const httplib::Request &,
        httplib::Response &response,
        const std::unique_ptr<IUserDataAccess>&userDataAccess,
        const std::unique_ptr<ITransactionDataAccess>&transactionDataAccess
) {
    std::string senderUserName ="ismail1";
    std::string receiverUserName ="ismail2";
    double amount =  10;
    OperationResult operationResult = TransactionUsecase::transfer(
            senderUserName,
            receiverUserName,
            amount,
            userDataAccess,
            transactionDataAccess
    );
    response.status = (int) operationResult.statusCode;
    if(operationResult.isSuccessful){
        response.set_content("status:success","text/plain");
    }else{
        response.set_content("status"+operationResult.message,"text/plain");
    }
}

void TransactionsHandlers::handleGetAllTransfers(
        const httplib::Request &,
        httplib::Response &response,
        const std::unique_ptr<ITransactionDataAccess> &transactionDataAccess
        ) {
    std::string userName = "ismail1";
    auto transactions = TransactionUsecase::getAllUserTransactions(userName,transactionDataAccess);
    std::cout<<transactions.size()<<'\n';
    std::string content;
    for(auto& transaction:transactions){
        content += "sender:"+transaction.sender+"\n"+"receiver:"+transaction.receiver+"\n"+"id:"+ std::to_string(transaction.id) + "\n";
    }
    response.set_content(content, "text/plain");
}