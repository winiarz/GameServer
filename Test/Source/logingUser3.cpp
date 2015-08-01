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
  tryToLoginUser("winiarz", "password1", LogingSuccessful, queueIds);  
  tryToLoginUser("winiarz", "password1", UserAlreadyLoged, queueIds);
  timeElapsed(300,  queueIds);
  tryToLoginUser("winiarz", "password1", LogingSuccessful, queueIds);  
  shutdownServer (queueIds);

    return 0;
}

