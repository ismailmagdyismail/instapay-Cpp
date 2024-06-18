#ifndef INSTAPAY_TRANSFERAUTHORIZER_HPP
#define INSTAPAY_TRANSFERAUTHORIZER_HPP

#include <unordered_map>
#include <vector>
#include "../../../../users/domain/UserType.hpp"
#include "../../../../presentation/OperationResult.hpp"

class TransferAuthorizer {
public:
    TransferAuthorizer(UserType senderType,UserType receiverType){
        this->senderType = senderType;
        this->receiverType = receiverType;
    }
    OperationResult isTransferValid();
private:
    UserType senderType;
    UserType receiverType;
    static std::unordered_map<UserType,std::vector<UserType>>authMapping;
};

#endif //INSTAPAY_TRANSFERAUTHORIZER_HPP
