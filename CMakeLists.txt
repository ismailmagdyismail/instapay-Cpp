cmake_minimum_required(VERSION 3.26)

project(instapay)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        ${PROJECT_NAME}
        src/main.cpp
        src/gateways/BankGateways/BankGateway.cpp
        src/gateways/BankGateways/BankGateway.hpp
        src/gateways/IGateway.hpp
        src/users/BankUser.hpp
        src/users/WalletUser.hpp
        src/users/UserProfile.hpp
        src/gateways/WalletGateways/WalletGateway.cpp
        src/gateways/WalletGateways/WalletGateway.hpp
        src/gateways/WalletGateways/MockWalletDB.cpp
        src/gateways/WalletGateways/MockWalletDB.hpp
        src/gateways/BankGateways/MockBankDB.cpp
        src/gateways/BankGateways/MockBankDB.hpp
        src/users/IUser.hpp
        src/users/IUser.hpp
)
