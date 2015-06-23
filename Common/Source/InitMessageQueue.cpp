#include "InitMessageQueue.hpp"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
#include <fstream>
using namespace std;

int initQueue(char keyStr[])
{
    key_t key = atoi(keyStr);
    int msgid = msgget(ftok("/tmp", key), (IPC_CREAT | 0600));
    if (msgid < 0) 
    {
        cerr << "ERROR: msgqid = " << msgid << endl;
    }
    return msgid;
}

MessageQueuesIds initMessageQueues(int argc, char* argv[])
{
    MessageQueuesIds queuesIds;

    if (argc <= 2) 
    {
        cerr << "missing argument: queue key!\n";
        return queuesIds;
    }

    queuesIds.inputQueue = initQueue(argv[1]);
    queuesIds.outputQueue = initQueue(argv[2]);

    ofstream msgqidFile ("msgqid1");
    msgqidFile << queuesIds.inputQueue;

    ofstream msgqidFile2 ("msgqid2");
    msgqidFile2 << queuesIds.outputQueue;
    return queuesIds;
}

