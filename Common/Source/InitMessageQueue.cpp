#include "InitMessageQueue.hpp"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
#include <fstream>
using namespace std;

int initMessageQueue(int argc, char* argv[])
{
    if (argc <= 1) 
    {
        cerr << "missing argument: queue key!\n";
        return -1;
    }
    key_t key = atoi(argv[0]);
    int msgqid = msgget(ftok("/tmp", key), (IPC_CREAT | 0600));
    ofstream msgqidFile ("msgqid");
    msgqidFile << msgqid;

    return msgqid;
}

