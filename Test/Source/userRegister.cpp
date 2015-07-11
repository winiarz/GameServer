#include "InitMessageQueue.hpp"
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"
#include "tryToRegisterUser.hpp"



int main(int argc, char* argv[])
{
    MessageQueuesIds queueIds = initMessageQueues(argc, argv);

    tryToRegisterUser("winiarz", "password1", ServerNotRunning, queueIds);

    return 0;
}
