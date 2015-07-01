#include"UserContainer.hpp"
#include<string.h>
#include <cstring>
#include"MsgUserRegisterResp.hpp"
void UserContainer::addUser (char username[], char password[])
{
    if ( this -> isRegisterPossible(username) )
        {
        strcpy (usernames[currentNumberOfUsers], username);
        strcpy (passwords[currentNumberOfUsers], password);
        currentNumberOfUsers++;
        //  - register successful
        }
}
bool  UserContainer::isRegisterPossible(char username[])
{
    bool possibleToRegist = true;
    if (currentNumberOfUsers == maxUsersNumber)
     {
     possibleToRegist = false;
     }//  "fail - too many users"
    else
    {
        for(int i=0;i<currentNumberOfUsers;i++)
        {
            if (strcmp( usernames [i], username ) == 0)
            {
            possibleToRegist = false;
            // kolejka grzecznie prosze wyslij  "- fail - username already used"
            }
        }
    }
    return possibleToRegist;
}
