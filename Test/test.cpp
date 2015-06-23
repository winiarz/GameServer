#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"
#include "InitMessageQueue.hpp"

bool getServerStatus(const MessageQueuesIds& queueIds)
{
    ServerInMessage statusReq;
    statusReq.msgType = msgServerStatusReq;
    int error = msgsnd( queueIds.outputQueue, &statusReq, sizeof(InnerServerInMessage), 0 );
    if (error) 
    {
        cout << "error in sending server status req!" << endl;
    }

    ServerOutMessage statusResp;
    msgrcv ( queueIds.inputQueue, &statusResp, sizeof(InnerServerOutMessage), 0, MSG_NOERROR );

    if (statusResp.msgType != msgServerStatusResp) 
    {
        cout << "wrong message received: " << statusResp.msgType << " expected: " << msgServerStatusResp << endl;
        exit(-1);
    }
    return statusResp.innerMessage.msgServerStatusResp.isServerRunning;
}


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

