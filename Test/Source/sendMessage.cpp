#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "sendMessage.hpp"
#include "ServerOutMessage.hpp"
#include "getServerStatus.hpp"

void timeElapsed(int seconds, MessageQueuesIds& queueIds)
{
   ServerInMessage m1;
   m1.msgType = msgIdServerControlReq;
   m1.innerMessage.msgServerControlReq.command = SecondElapsed;
  for(int i=0;i<seconds;i++)
  {
    sendMessage(queueIds, m1);
  }
}

void sendMessage(const MessageQueuesIds& queuesIds,
                 ServerInMessage& message)
{
    int error = msgsnd( queuesIds.outputQueue, &message, sizeof(InnerServerInMessage), 0 );
    if (error != 0) 
    {
        cerr << "error in sending message: " << error << endl;
        exit(-1);
    }
}

void startServer (const MessageQueuesIds& queuesIds)
{
    ServerInMessage m1;
    m1.msgType = msgIdServerControlReq;
    m1.innerMessage.msgServerControlReq.command = Start;
    sendMessage(queuesIds, m1);
}
void shutdownServer (const MessageQueuesIds& queuesIds)
{
    ServerInMessage m1;
    m1.msgType = msgIdServerControlReq;
    m1.innerMessage.msgServerControlReq.command = ServerShutdown;
    sendMessage(queuesIds, m1);
}