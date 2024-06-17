#include "./TransferAuthorizer.hpp"

std::unordered_map<UserType,std::vector<UserType>> TransferAuthorizer::authMapping  = {
        { UserType::BANK_USER , std::vector{UserType::BANK_USER, UserType::WALLET_USER} },
        { UserType::WALLET_USER , std::vector{UserType::WALLET_USER} },
} ;

Response TransferAuthorizer::isTransferValid() {
    bool isValidTransfer =std::find(
            TransferAuthorizer::authMapping[this->senderType].begin(),
            TransferAuthorizer::authMapping[this->receiverType].end(),receiverType
    ) != TransferAuthorizer::authMapping[this->senderType].end();
    if(!isValidTransfer){
        return Response{false,403,"UnAuthorized execute a transfer" };
    }
    return Response{true,200,""};
}