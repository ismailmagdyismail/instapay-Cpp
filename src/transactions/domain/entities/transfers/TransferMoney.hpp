#ifndef INSTAPAY_TRANSFERMONEY_HPP
#define INSTAPAY_TRANSFERMONEY_HPP


#include "../ITransaction.hpp"
#include "../../../../gateways/IGateway.hpp"
#include "TransferAuthorizer.hpp"

class TransferMoney final: public ITransaction{
public:
    TransferMoney(
            std::unique_ptr<IGateway>&&senderGateway,
            std::unique_ptr<IGateway>&& receiverGateway,
            std::unique_ptr<TransferAuthorizer>&& transferAuth
            );
    virtual OperationResult execute(const double& amount)override;
private:
    std::unique_ptr<IGateway> senderGateway;
    std::unique_ptr<IGateway> receiverGateway;
    std::unique_ptr<TransferAuthorizer> transferAuth;
};


#endif //INSTAPAY_TRANSFERMONEY_HPP
