#include "InitMessageQueue.hpp"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
#include <fstream>
using namespace std;

MessageQueuesIds initMessageQueues(int argc, char* argv[])
{
    MessageQueuesIds queuesIds;

    if (argc <= 2) 
    {
        cerr << "missing argument: queue key!\n";
        return queuesIds;
    }

    key_t keyForInputQueue = atoi(argv[1]);
    key_t keyForOutputQueue = atoi(argv[2]);

    queuesIds.inputQueue = msgget(ftok("/tmp", keyForInputQueue), (IPC_CREAT | 0600));
    if (queuesIds.inputQueue < 0) 
    {
        cerr << "ERROR: msgqid = " << queuesIds.inputQueue << endl;
    }

    queuesIds.outputQueue = msgget(ftok("/tmp", keyForOutputQueue), (IPC_CREAT | 0600));
    if (queuesIds.outputQueue < 0) 
    {
        cerr << "ERROR: msgqid = " << queuesIds.outputQueue << endl;
    }

    ofstream msgqidFile ("msgqid");
    msgqidFile << queuesIds.inputQueue;
    return queuesIds;
}

