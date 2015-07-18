#include "tryToLoginUser.hpp"
#include "tryToRegisterUser.hpp"
#include "InitMessageQueue.hpp"
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"
#include "sendMessage.hpp"
int main(int argc, char* argv[])
{
  MessageQueuesIds queueIds = initMessageQueues(argc, argv);
    startServer (queueIds);
  tryToRegisterUser("winiarz", "password1", RegisterSuccessful, queueIds);   
  tryToRegisterUser("mieciu", "password3", RegisterSuccessful, queueIds);
  int sessionId_1 = tryToLoginUser("winiarz", "password1", LogingSuccessful, queueIds);
  int sessionId_2 = tryToLoginUser("mieciu", "password3", LogingSuccessful, queueIds);
  if (sessionId_1 == sessionId_2) exit(-1);
  shutdownServer (queueIds);

    return 0;
}