#include "TransactionsHandlers.hpp"
#include "../usecase/TransactionsUsecase.hpp"
#include "../../../json/single_include/nlohmann/json.hpp"


void TransactionsHandlers::handleTransfer(
        const httplib::Request& request,
        httplib::Response &response,
        const std::unique_ptr<IUserDataAccess>&userDataAccess,
        const std::unique_ptr<ITransactionDataAccess>&transactionDataAccess
) {
    response.set_header("Content-Type","application/json");
    using json = nlohmann::json;
    json responseBody ;

    auto body = json::parse(request.body);
    std::string senderUserName = body["senderUserName"];
    std::string receiverUserName = body["receiverUserName"];
    if(senderUserName.empty() || receiverUserName.empty()){
        response.status = 400;
        responseBody["status"] = "fail",
        responseBody["message"] = "must specify both sender and receiver user names";
        response.set_content(responseBody.dump(),"application/json");
        return ;
    }

    double amount =  10;
    OperationResult operationResult = TransactionUsecase::transfer(
            senderUserName,
            receiverUserName,
            amount,
            userDataAccess,
            transactionDataAccess
    );
    if(operationResult.isSuccessful){
        responseBody["status"] = "success",
        responseBody["message"] = "transactions executed successfully";
    }else{
        responseBody["status"] = "fail",
        responseBody["message"] = operationResult.message;
    }
    response.status = (int) operationResult.statusCode;
    response.set_content(responseBody.dump(),"application/json");
    response.set_content(responseBody.dump(),"application/json");

}

void TransactionsHandlers::handleGetAllTransfers(
        const httplib::Request& request,
        httplib::Response &response,
        const std::unique_ptr<ITransactionDataAccess> &transactionDataAccess
        ) {
    response.set_header("Content-Type","application/json");
    using json = nlohmann::json;
    json responseBody ;
    std::string userName = request.get_param_value("userName");

    if(userName.empty()){
        responseBody["status"] = "fail";
        responseBody["message"] = "must specify user name";
        response.set_content(responseBody.dump(),"application/json");
        return;
    }

    auto transactions = TransactionUsecase::getAllUserTransactions(userName,transactionDataAccess);
    std::string content;
    json transactionsContent = json::array();
    for(auto& transaction:transactions){
        json transactionContent;
        transactionContent["id"] = transaction.id;
        transactionContent["sender"] = transaction.sender;
        transactionContent["receiver"] = transaction.receiver;
        transactionsContent.push_back(transactionContent);
    }
    responseBody["status"] = "success";
    responseBody["transactions"] = transactionsContent;
    response.set_content(responseBody.dump(), "application/json");
}