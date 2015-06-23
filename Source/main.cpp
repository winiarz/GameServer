#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "ServerInMessage.hpp"
#include "InitMessageQueue.hpp"
#include "Debug.hpp"

int main(int argc, char* argv[])
{
    DEBUG << "Server start!";
    int msqid = initMessageQueue(argc, argv);

    ServerInMessage m1;

    while (true) 
    {
        int bytesReceived = msgrcv ( msqid, &m1, sizeof(InnerServerInMessage), 1, MSG_NOERROR );

        if (bytesReceived != sizeof(InnerServerInMessage)) 
        {
            DEBUG << "error during msgrcv: " << bytesReceived;
            return -1;
        }

        switch (m1.msgType) 
        {
        case msgIdServerControlReq:
            DEBUG << "Message received = '" << m1.innerMessage.msgServerControlReq.command << "'";

            if (m1.innerMessage.msgServerControlReq.command == ServerShutdown) 
            {
                DEBUG << "Server shutdown!";
                return 0;
            }
            else if (m1.innerMessage.msgServerControlReq.command == ServerRestart) 
            {
                DEBUG << "Server restart!";
            }
            break;
        }
    }
}

