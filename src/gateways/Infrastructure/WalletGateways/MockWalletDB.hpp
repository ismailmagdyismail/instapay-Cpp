#ifndef INSTAPAY_MOCKWALLETDB_HPP
#define INSTAPAY_MOCKWALLETDB_HPP

#include <iostream>
#include <optional>
#include <unordered_map>
#include "../../../presentation/Response.h"

class MockWalletDB {
public:
    static bool isRegisteredUser(const std::string& phoneNumber);
    static std::optional<double> getUserBalance(const std::string& phoneNumber);
    static Response updateUserBalance(const std::string& phoneNumber, const double& newBalance);
    static Response addUser(const std::string& phoneNumber);

private:
    static std::unordered_map<std::string,double>db;
    struct Initializer{
        // To run once program is loaded into memory (since it is static) so DB is seeded
        Initializer(){
            seedDB();
        }
    };
    static void seedDB(){
        MockWalletDB::db["011223455"] = 1000.0;
    }
    static Initializer initializer ;
};

#endif //INSTAPAY_MOCKWALLETDB_HPP
