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
    bool l_isServerRunning = isServerRunning(queueIds);
    if (l_isServerRunning) 
    {
        cout << "fail: server should not be running at the begining!" << endl;
        exit(-1);
    }
    startServer (queueIds);
    l_isServerRunning = isServerRunning(queueIds);
    if (not l_isServerRunning) 
    {
        cout << "fail: server should be running after receiving Start message!" << endl;
        exit(-1);
    }
    shutdownServer (queueIds);
    return 0;
}

