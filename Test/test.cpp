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
    m1.command = ServerShutdown;

    int error = msgsnd( msqid, &m1, sizeof(MsgServerControlReq), 0 );
    cout << "error = " << error << endl;

    return error;
}

