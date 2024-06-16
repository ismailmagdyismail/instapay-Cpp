#ifndef INSTAPAY_MOCKBANKDB_HPP
#define INSTAPAY_MOCKBANKDB_HPP
#include <iostream>
#include <unordered_map>

class MockBankDB {
public:
    static bool isRegisteredUser(std::string accountNumber);
    static std::optional<double> getUserBalance(std::string accountNumber);
    static std::optional<std::string>updateUserBalance(std::string accountNumber,double newBalance);
    static std::optional<std::string>addUser(std::string accountNumber);

private:
    static std::unordered_map<std::string,double>db;
    struct Initializer{
        // To run once program is loaded into memory (since it is static) so DB is seeded
        Initializer(){
            seedDB();
        }
    };
    static void seedDB(){
        MockBankDB::db["011223455"] = 1000.0;
    }
    static Initializer initializer ;
};


#endif //INSTAPAY_MOCKBANKDB_HPP
