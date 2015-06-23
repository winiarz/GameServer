#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "ServerInMessage.hpp"
#include "InitMessageQueue.hpp"

int main(int argc, char* argv[])
{
    MessageQueuesIds queueIds = initMessageQueues(argc, argv);

    ServerInMessage m1;
    m1.msgType = 1;
    m1.innerMessage.msgServerControlReq.command = ServerRestart;
    int error = msgsnd( queueIds.outputQueue, &m1, sizeof(InnerServerInMessage), 0 );

    m1.innerMessage.msgServerControlReq.command = ServerShutdown;
    error = msgsnd( queueIds.outputQueue, &m1, sizeof(InnerServerInMessage), 0 );
    cout << "error = " << error << endl;

    return error;
}

