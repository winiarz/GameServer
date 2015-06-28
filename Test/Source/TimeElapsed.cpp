#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"
#include "InitMessageQueue.hpp"
#include "getServerStatus.hpp"
#include "sendMessage.hpp"

int main(int argc, char* argv[])
{
    MessageQueuesIds queueIds = initMessageQueues(argc, argv);
    ServerInMessage m1;
    m1.msgType = msgIdServerControlReq;
    m1.innerMessage.msgServerControlReq.command = Start;
    sendMessage(queueIds, m1);
    m1.innerMessage.msgServerControlReq.command = SecondElapsed;
    sendMessage(queueIds, m1);

    int l_timeOnServer = getServerTime(queueIds);
    if (l_timeOnServer != 1) 
    {
        cerr << "expected time os server = 1, actual = " << l_timeOnServer << endl;
        exit(-1);
    }

    m1.innerMessage.msgServerControlReq.command = ServerShutdown;
    sendMessage(queueIds, m1);

    return 0;
}

