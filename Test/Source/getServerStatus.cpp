#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "getServerStatus.hpp"
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"

bool isServerRunning(const MessageQueuesIds& queueIds)
{
    ServerInMessage statusReq;
    statusReq.msgType = msgIdServerStatusReq;
    int error = msgsnd( queueIds.outputQueue, &statusReq, sizeof(InnerServerInMessage), 0 );
    if (error)
    {
        cout << "error in sending server status req!" << endl;
        exit(-1);
    }

    ServerOutMessage statusResp;
    msgrcv ( queueIds.inputQueue, &statusResp, sizeof(InnerServerOutMessage), 0, MSG_NOERROR );

    if (statusResp.msgType != msgIdServerStatusResp)
    {
        cout << "wrong message received: " << statusResp.msgType << " expected: " << msgIdServerStatusResp << endl;
        exit(-1);
    }
    return statusResp.innerMessage.msgServerStatusResp.isServerRunning;
}

int getServerTime(const MessageQueuesIds& queueIds)
{
    ServerInMessage statusReq;
    statusReq.msgType = msgIdServerStatusReq;
    int error = msgsnd( queueIds.outputQueue, &statusReq, sizeof(InnerServerInMessage), 0 );
    if (error)
    {
        cout << "error in sending server status req!" << endl;
        exit(-1);
    }
    ServerOutMessage statusResp;
    msgrcv ( queueIds.inputQueue, &statusResp, sizeof(InnerServerOutMessage), 0, MSG_NOERROR );
    if (statusResp.msgType != msgIdServerStatusResp)
    {
        cout << "wrong message received: " << statusResp.msgType << " expected: " << msgIdServerStatusResp << endl;
        exit(-1);
    }
    return statusResp.innerMessage.msgServerStatusResp.secondsCounter;
}


