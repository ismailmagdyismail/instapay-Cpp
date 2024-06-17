#ifndef INSTAPAY_TRANSFERUSECASE_HPP
#define INSTAPAY_TRANSFERUSECASE_HPP

#include <unordered_map>
#include "../domain/entities/ITransaction.hpp"
#include "../domain/entities/transfers/TransferMoney.hpp"
#include "../../users/dataAccess/IUserDataAccess.hpp"

namespace TransferUseCase {
    Response execute(
            const std::string& senderUserName,
            const std::string& receiverUserName,
            const double& amount,
            const std::unique_ptr<IUserDataAccess>&userDataAccess
            );
};


#endif
