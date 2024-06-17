#include <memory>
#include <cassert>
#include "../gateways/IGateway.hpp"
#include "../gateways/Infrastructure/BankGateways/MockBankGateway.hpp"
#include "GatewayTests.hpp"
#include "../gateways/Infrastructure/WalletGateways/MockWalletGateway.hpp"

void GatewayTests::run() {
    GatewayTests::testMockBankGateway();
    GatewayTests::testMockWalletGateway();
}

void GatewayTests::testMockBankGateway() {
    std::cout<<"=======....MockBankGateway tests....=======\n";
    const double DEPOSIT_AMOUNT = 1040;
    std::unique_ptr<IGateway> gateway = std::make_unique<MockBankGateway>("011223455");
    double oldBalance = gateway->getBalance().value_or(0);
    gateway->deposit(DEPOSIT_AMOUNT);
    assert(oldBalance+DEPOSIT_AMOUNT == gateway->getBalance().value_or(0));

    const double WITHDRAW_AMOUNT = 1040;
    oldBalance = gateway->getBalance().value_or(0);
    gateway->withdraw(WITHDRAW_AMOUNT);
    assert(oldBalance-WITHDRAW_AMOUNT == gateway->getBalance().value_or(0));
    assert(gateway->withdraw(100000).has_value());
}

void GatewayTests::testMockWalletGateway() {
    std::cout<<"=======....MockWalletGateway tests....=======\n";
    const double DEPOSIT_AMOUNT = 1040;
    std::unique_ptr<IGateway> gateway = std::make_unique<MockWalletGateway>("011223455");
    double oldBalance = gateway->getBalance().value_or(0);
    gateway->deposit(DEPOSIT_AMOUNT);
    assert(oldBalance + DEPOSIT_AMOUNT == gateway->getBalance().value_or(0));

    const double WITHDRAW_AMOUNT = 1040;
    oldBalance = gateway->getBalance().value_or(0);
    gateway->withdraw(WITHDRAW_AMOUNT);
    assert(oldBalance-WITHDRAW_AMOUNT == gateway->getBalance().value_or(0));
    assert(gateway->withdraw(100000).has_value());
}

