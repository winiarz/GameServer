#include"UserContainer.hpp"
#include<string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include "InitMessageQueue.hpp"
#include "ServerOutMessage.hpp"
#include"MsgUserRegisterResp.hpp"
void UserContainer::addUser (char username[], char password[], MessageQueuesIds queueIds)
{
    if ( this -> isRegisterPossible(username, queueIds) )
        {
        strcpy (usernames[currentNumberOfUsers], username);
        strcpy (passwords[currentNumberOfUsers], password);
        currentNumberOfUsers++;
            MsgUserRegisterResp resp;
            resp.userRegisterStatus = RegisterSuccessful;
            ServerOutMessage serverOutMessage;
            serverOutMessage.msgType = msgIdUserRegisterResp;
            serverOutMessage.innerMessage.msgUserRegisterResp = resp;
            msgsnd( queueIds.outputQueue, &serverOutMessage, sizeof(InnerServerOutMessage), 0 );
        }
}
bool  UserContainer::isRegisterPossible(char username[], MessageQueuesIds queueIds)
{
    bool possibleToRegist = true;
    if (currentNumberOfUsers == maxUsersNumber)
     {
     possibleToRegist = false;
     MsgUserRegisterResp resp;
     resp.userRegisterStatus = TooManyUsers;
     ServerOutMessage serverOutMessage;
     serverOutMessage.msgType = msgIdUserRegisterResp;
     serverOutMessage.innerMessage.msgUserRegisterResp = resp;
     msgsnd( queueIds.outputQueue, &serverOutMessage, sizeof(InnerServerOutMessage), 0 );
     }//  "fail - too many users"
    else
    {
        for(int i=0;i<currentNumberOfUsers;i++)
        {
            if (strcmp( usernames [i], username ) == 0)
            {
            possibleToRegist = false;
            MsgUserRegisterResp resp;
            resp.userRegisterStatus = UsernameAlreadyUsed;
            ServerOutMessage serverOutMessage;
            serverOutMessage.msgType = msgIdUserRegisterResp;
            serverOutMessage.innerMessage.msgUserRegisterResp = resp;
            msgsnd( queueIds.outputQueue, &serverOutMessage, sizeof(InnerServerOutMessage), 0 );
            // kolejka grzecznie prosze wyslij  "- fail - username already used"
            }
        }
    }
    return possibleToRegist;
}
