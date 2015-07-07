#include"UserContainer.hpp"
#include<string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include "InitMessageQueue.hpp"
#include "ServerOutMessage.hpp"
#include"MsgUserRegisterResp.hpp"
#include "SendingFunctions.hpp"



void UserContainer::addUser (char username[], char password[], MessageQueuesIds queueIds)
{
    if ( this -> isRegisterPossible(username, queueIds) )
        {
        strcpy (usernames[currentNumberOfUsers], username);
        strcpy (passwords[currentNumberOfUsers], password);
        currentNumberOfUsers++;
        sendingUserRegisterStatus (RegisterSuccessful, queueIds);
        }
}
bool  UserContainer::isRegisterPossible(char username[], MessageQueuesIds queueIds)
{
    bool possibleToRegist = true;
    if (currentNumberOfUsers == maxUsersNumber)
     {
     possibleToRegist = false;
     sendingUserRegisterStatus (TooManyUsers, queueIds);
     }
    else
    {
        for(int i=0;i<currentNumberOfUsers;i++)
        {
            if (strcmp( usernames [i], username ) == 0)
            {
            possibleToRegist = false;
            sendingUserRegisterStatus (UsernameAlreadyUsed, queueIds);
            }
        }
    }
    return possibleToRegist;
}
