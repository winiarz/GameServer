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
    startServer (queueIds);
    ServerInMessage m1;
    m1.msgType = msgIdServerControlReq;
    m1.innerMessage.msgServerControlReq.command = SecondElapsed;
    sendMessage(queueIds, m1);

    int l_timeOnServer = getServerTime(queueIds);
    if (l_timeOnServer != 1) 
    {
        cerr << "expected time os server = 1, actual = " << l_timeOnServer << endl;
        exit(-1);
    }

    shutdownServer (queueIds);

    return 0;
}

