#include "InitMessageQueue.hpp"
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"
#include "tryToRegisterUser.hpp"
#include "sendMessage.hpp"


int main(int argc, char* argv[])
{
    MessageQueuesIds queueIds = initMessageQueues(argc, argv);
    tryToRegisterUser("winiarz", "password1", ServerNotRunning, queueIds);
    startServer (queueIds);
    tryToRegisterUser("winiarz", "password1", RegisterSuccessful, queueIds);
    tryToRegisterUser("winiarz", "password2", UsernameAlreadyUsed, queueIds);
    tryToRegisterUser("mieciu", "password3", RegisterSuccessful, queueIds);
    shutdownServer (queueIds);
    return 0;
}
