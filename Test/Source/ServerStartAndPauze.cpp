#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"
#include "InitMessageQueue.hpp"
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

int main(int argc, char* argv[])
{
    MessageQueuesIds queueIds = initMessageQueues(argc, argv);

    ServerInMessage m1;
    m1.msgType = msgIdServerControlReq;
    m1.innerMessage.msgServerControlReq.command = ServerRestart;

    sendMessage(queueIds, m1);

    bool isServerRunning = getServerStatus(queueIds);
    if (isServerRunning) 
    {
        cout << "fail: server should not be running at the begining!" << endl;
        exit(-1);
    }

    m1.innerMessage.msgServerControlReq.command = Start;
    sendMessage(queueIds, m1);

    isServerRunning = getServerStatus(queueIds);
    if (not isServerRunning) 
    {
        cout << "fail: server should be running after receiving Start message!" << endl;
        exit(-1);
    }

    m1.innerMessage.msgServerControlReq.command = ServerShutdown;
    sendMessage(queueIds, m1);

    return 0;
}

