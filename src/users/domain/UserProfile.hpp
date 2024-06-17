#ifndef USER_PROFILE_HPP_
#define USER_PROFILE_HPP_

#include <iostream>

struct UserProfile{
   const std::string userName;
   const std::string password;
   const std::string phoneNumber;
   UserProfile(const UserProfile& other) = default ;
};

#endif
