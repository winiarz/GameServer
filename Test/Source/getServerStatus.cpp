#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "getServerStatus.hpp"
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"

bool getServerStatus(const MessageQueuesIds& queueIds)
{
    ServerInMessage statusReq;
    statusReq.msgType = msgServerStatusReq;
    int error = msgsnd( queueIds.outputQueue, &statusReq, sizeof(InnerServerInMessage), 0 );
    if (error) 
    {
        cout << "error in sending server status req!" << endl;
        exit(-1);
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
