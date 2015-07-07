#include<string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include "InitMessageQueue.hpp"
#include "ServerOutMessage.hpp"
#include"MsgUserRegisterResp.hpp"

#include"SendingFunctions.hpp"
void sendingUserRegisterStatus (UserRegisterStatus userRegisterStatus, MessageQueuesIds queueIds)
{
    MsgUserRegisterResp resp;
    resp.userRegisterStatus = userRegisterStatus;
    ServerOutMessage serverOutMessage;
    serverOutMessage.msgType = msgIdUserRegisterResp;
    serverOutMessage.innerMessage.msgUserRegisterResp = resp;
    msgsnd( queueIds.outputQueue, &serverOutMessage, sizeof(InnerServerOutMessage), 0 );
}
void sendingServerStatus (bool isServerRunning, int secondsCounter, MessageQueuesIds queueIds)
{
    MsgServerStatusResp resp;
    resp.isServerRunning = isServerRunning;
    resp.secondsCounter = secondsCounter;
    ServerOutMessage serverOutMessage;
    serverOutMessage.msgType = msgIdServerStatusResp;
    serverOutMessage.innerMessage.msgServerStatusResp = resp;
    msgsnd( queueIds.outputQueue, &serverOutMessage, sizeof(InnerServerOutMessage), 0 );
}
