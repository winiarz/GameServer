#include "InitMessageQueue.hpp"
#include"MsgUserRegisterResp.hpp"

class UserContainer
{
public:
    void addUser (char username[], char password[], MessageQueuesIds queueIds);
    bool  isRegisterPossible(char username[], MessageQueuesIds queueIds);
    void loginUser (char username[], char password[], MessageQueuesIds queueIds);
    bool  isLogingPossible(char username[],char password[], MessageQueuesIds queueIds);
private:
    int static const maxUsersNumber = 100;
    int currentNumberOfUsers = 0;
    char usernames [maxUsersNumber][30];
    char passwords [maxUsersNumber][30];
};
void sendingUserRegisterStatus (UserRegisterStatus , MessageQueuesIds );
