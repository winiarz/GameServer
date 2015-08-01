#pragma once
#include "InitMessageQueue.hpp"
#include"MsgUserRegisterResp.hpp"
#include"SessionIdContainer.hpp"

extern int secondsCounter;

class UserContainer
{
public:
    void addUser (char username[], char password[], MessageQueuesIds queueIds);
    bool  isRegisterPossible(char username[], MessageQueuesIds queueIds);
    void loginUser (char username[], char password[], MessageQueuesIds queueIds);
    void  isLogingPossible(char username[],char password[], MessageQueuesIds queueIds);
    UserContainer ();
private:
    int static const maxUsersNumber = 100;
    int currentNumberOfUsers = 0;
    SessionIdContainer sessionIdContainer;
    char usernames [maxUsersNumber][30];
    char passwords [maxUsersNumber][30];
};
void sendingUserRegisterStatus (UserRegisterStatus , MessageQueuesIds );
