#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "MsgServerControlReq.hpp"
#include "InitMessageQueue.hpp"
#include "Debug.hpp"

int main(int argc, char* argv[])
{
    DEBUG << "Server start!";
    int msqid = initMessageQueue(argc, argv);

    MsgServerControlReq m1;

    while (true) 
    {
        int bytesReceived = msgrcv ( msqid, &m1, sizeof(ServerControlCommand), 1, MSG_NOERROR );

        if (bytesReceived != sizeof(ServerControlCommand)) 
        {
            DEBUG << "error during msgrcv: " << bytesReceived;
            return -1;
        }

        DEBUG << "Message received = '" << m1.command << "'";

        if (m1.command == ServerShutdown) 
        {
            DEBUG << "Server shutdown!\n";
            break;
        }
    }
}

