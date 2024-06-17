#ifndef INSTAPAY_TRANSFERMONEY_HPP
#define INSTAPAY_TRANSFERMONEY_HPP


#include "ITransaction.hpp"
#include "../../gateways/IGateway.hpp"

class TransferMoney final: public ITransaction{
public:
    TransferMoney(std::unique_ptr<IGateway>&&senderGateway,std::unique_ptr<IGateway>&& receiverGateway);
    virtual const Response execute(const double& amount)override;
private:
    std::unique_ptr<IGateway> senderGateway;
    std::unique_ptr<IGateway> receiverGateway;
};


#endif //INSTAPAY_TRANSFERMONEY_HPP
