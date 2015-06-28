#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "sendMessage.hpp"
#include "ServerOutMessage.hpp"
#include "getServerStatus.hpp"

void sendMessage(const MessageQueuesIds& queuesIds,
                 ServerInMessage& message)
{
    int error = msgsnd( queuesIds.outputQueue, &message, sizeof(InnerServerInMessage), 0 );
    if (error != 0) 
    {
        cerr << "error in sending message: " << error << endl;
        exit(-1);
    }
}
