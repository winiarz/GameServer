#include"UserContainer.hpp"
#include<string.h>
#include <cstring>
#include"MsgUserRegisterResp.hpp"
void UserContainer::addUser (char username[], char password[])
{
this -> userRegisterResp(username);
strcpy (usernames[currentNumberOfUsers], username);
strcpy (passwords[currentNumberOfUsers], password);
currentNumberOfUsers++;// bo nigdzie tego nie robie chyba
//  - register successful
}
void  UserContainer::userRegisterResp(char username[])
{
    if (currentNumberOfUsers == maxUsersNumber) {}//  "fail - too many users"
    else
    {
        for(int i=0;i<currentNumberOfUsers;i++)
        {
            if (strcmp( usernames [i], username ) == 0)
            {
            // kolejka grzecznie prosze wyslij  "- fail - username already used"
            }
        }
    }

}
