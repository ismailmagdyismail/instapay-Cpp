#include "MockBankGateway.hpp"
#include "MockBankDB.hpp"

MockBankGateway::MockBankGateway(const std::string &bankAccountNumber) {
    this->bankAccountNumber = bankAccountNumber;
}

Response MockBankGateway::deposit(const double &amount){
    std::optional<double> balance = MockBankDB::getUserBalance(this->bankAccountNumber);
    if(!balance.has_value()){
        return Response{false,404,"No Wallet exists for this phone number" +this->bankAccountNumber};
    }
    return MockBankDB::updateUserBalance(this->bankAccountNumber,balance.value() + amount);
}

Response MockBankGateway::withdraw(const double &amount){
    std::optional<double> balance = MockBankDB::getUserBalance(this->bankAccountNumber);
    if(!balance.has_value()){
        return Response{false,404,"No Wallet exists for this phone number" +this->bankAccountNumber};
    }
    return MockBankDB::updateUserBalance(this->bankAccountNumber,balance.value() - amount);
}

std::optional<double> MockBankGateway::getBalance()const {
    return MockBankDB::getUserBalance(this->bankAccountNumber);
}

