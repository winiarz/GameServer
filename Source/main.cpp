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
        int error = msgrcv ( msqid, &m1, sizeof(MsgServerControlReq), 1, 0 );
        if (error < 0) 
        {
            DEBUG << "error during msgrcv: " << error;
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

