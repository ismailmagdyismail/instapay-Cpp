#include "TransferMoney.hpp"


TransferMoney::TransferMoney(std::unique_ptr<IGateway>&& senderGateway,
                              std::unique_ptr<IGateway>&& receiverGateway) {
    this->senderGateway = std::move(senderGateway);
    this->receiverGateway = std::move(receiverGateway);
}

const Response TransferMoney::execute(const double &amount) {
    // TODO : this logic of Transferring and atomicity should be Handled by the 3rrd party API service
    auto response = this->senderGateway->withdraw(amount);
    if(!response.isSuccessful){
        return response;
    }
    response = this->receiverGateway->deposit(amount);
    if(!response.isSuccessful){ // UNDO sender operation , redeposit his money back to him
        this->senderGateway->deposit(amount);
    }
    return response;
}