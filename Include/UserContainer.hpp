#include "InitMessageQueue.hpp"

class UserContainer
{
public:
    void addUser (char username[], char password[], MessageQueuesIds queueIds);
    bool  isRegisterPossible(char username[], MessageQueuesIds queueIds);
private:
    int static const maxUsersNumber = 100;
    int currentNumberOfUsers = 0;
    char usernames [maxUsersNumber][30];
    char passwords [maxUsersNumber][30];
};
