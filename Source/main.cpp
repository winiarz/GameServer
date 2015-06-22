#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "MsgServerControlReq.hpp"
#include "InitMessageQueue.hpp"

int main(int argc, char* argv[])
{
    int msqid = initMessageQueue(argc, argv);

    MsgServerControlReq m1;

    while (true) 
    {
        int error = msgrcv ( msqid, &m1, sizeof(MsgServerControlReq), 1, 0 );
        if (error < 0) 
        {
            cout << "error during msgrcv: " << error << endl;
            return -1;
        }
        cout << "Message received = '" << m1.command << "'\n";

        if (m1.command == ServerShutdown) 
        {
            cout << "Server shutdown!\n";
            break;
        }
    }
}

