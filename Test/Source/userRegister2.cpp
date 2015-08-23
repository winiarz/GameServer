#include "InitMessageQueue.hpp"
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"
#include "tryToRegisterUser.hpp"
#include "sendMessage.hpp"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    MessageQueuesIds queueIds = initMessageQueues(argc, argv);
    startServer (queueIds);
    char userName ;
    for(int i=0;i < 100; i++)
    {
      userName = i;
      tryToRegisterUser(& userName, "password", RegisterSuccessful, queueIds);
    }
    tryToRegisterUser("winiarz", "password2", TooManyUsers, queueIds);
    shutdownServer (queueIds);
    return 0;
}
