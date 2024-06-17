#include "InMemoryUsers.hpp"

unsigned int InMemoryUsers::getUsersCount() const {
    return this->db.size();
}

std::optional<Response> InMemoryUsers::addUser(const std::unique_ptr<IUser>& newUser) {
    const std::string userName = newUser->getUserProfile().userName;
    if( this->db.find(userName) != this->db.end()){
        return Response{ false, 401, "user already exists with this data"};
    }
    this->db[userName] = newUser->clone();
    return Response{true,200,""};
}

std::optional<IUser*> InMemoryUsers::getUserByPhoneNumber(const std::string &phoneNumber) const{
    for(auto& entry : this->db){
        if(entry.first == phoneNumber){
            return entry.second.get();
        }
    }
    return {};
}

std::optional<IUser*> InMemoryUsers::getUserByUserName(const std::string& userName)const{
    auto it = this->db.find(userName);
    if (it != this->db.end()) {
        return it->second.get();
    }
    return {};
}
