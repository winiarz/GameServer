#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"
#include "InitMessageQueue.hpp"
#include "getServerStatus.hpp"

int main(int argc, char* argv[])
{
    MessageQueuesIds queueIds = initMessageQueues(argc, argv);

    ServerInMessage m1;
    m1.msgType = msgIdServerControlReq;
    m1.innerMessage.msgServerControlReq.command = ServerRestart;
    int error = msgsnd( queueIds.outputQueue, &m1, sizeof(InnerServerInMessage), 0 );

    bool isServerRunning = getServerStatus(queueIds);
    if (isServerRunning) 
    {
        cout << "fail: server should not be running at the begining!" << endl;
        exit(-1);
    }

    m1.innerMessage.msgServerControlReq.command = Start;
    error = msgsnd( queueIds.outputQueue, &m1, sizeof(InnerServerInMessage), 0 );

    isServerRunning = getServerStatus(queueIds);
    if (not isServerRunning) 
    {
        cout << "fail: server should be running after receiving Start message!" << endl;
        exit(-1);
    }

    m1.innerMessage.msgServerControlReq.command = ServerShutdown;
    error = msgsnd( queueIds.outputQueue, &m1, sizeof(InnerServerInMessage), 0 );
    cout << "error = " << error << endl;

    return error;
}

