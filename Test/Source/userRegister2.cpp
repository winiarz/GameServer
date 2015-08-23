#include "InitMessageQueue.hpp"
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"
#include "tryToRegisterUser.hpp"
#include "sendMessage.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
    MessageQueuesIds queueIds = initMessageQueues(argc, argv);
    startServer (queueIds);
    for(int i=0;i < 1000; i++)
    {
      tryToRegisterUser(to_string(i), "password", RegisterSuccessful, queueIds);
    }
    tryToRegisterUser("winiarz", "password2", TooManyUsers, queueIds);
    shutdownServer (queueIds);
    return 0;
}
