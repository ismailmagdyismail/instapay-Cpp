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
    const double ADD_AMOUNT = 1040;
    std::unique_ptr<IGateway> gateway = std::make_unique<MockBankGateway>("011223455");
    double oldBalance = gateway->getBalance().value_or(0);
    gateway->deposit(ADD_AMOUNT);
    assert(oldBalance+ADD_AMOUNT == gateway->getBalance().value_or(0));
}

void GatewayTests::testMockWalletGateway() {
    std::cout<<"=======....MockWalletGateway tests....=======\n";
    const double ADD_AMOUNT = 1040;
    std::unique_ptr<IGateway> gateway = std::make_unique<MockWalletGateway>("011223455");
    double oldBalance = gateway->getBalance().value_or(0);
    gateway->deposit(ADD_AMOUNT);
    assert(oldBalance+ADD_AMOUNT == gateway->getBalance().value_or(0));
}

