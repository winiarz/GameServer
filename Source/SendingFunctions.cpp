#include<string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include "InitMessageQueue.hpp"
#include "ServerOutMessage.hpp"
#include"MsgUserRegisterResp.hpp"
#include"SendingFunctions.hpp"
#include"UserContainer.hpp"

void sendingUserRegisterStatus (UserRegisterStatus userRegisterStatus, MessageQueuesIds queueIds)
{
    MsgUserRegisterResp resp;
    resp.userRegisterStatus = userRegisterStatus;
    ServerOutMessage serverOutMessage;
    serverOutMessage.msgType = msgIdUserRegisterResp;
    serverOutMessage.innerMessage.msgUserRegisterResp = resp;
    msgsnd( queueIds.outputQueue, &serverOutMessage, sizeof(InnerServerOutMessage), 0 );
}
void sendingServerStatus (bool isServerRunning,  MessageQueuesIds queueIds)
{
    MsgServerStatusResp resp;
    resp.isServerRunning = isServerRunning;
    resp.secondsCounter = secondsCounter;
    ServerOutMessage serverOutMessage;
    serverOutMessage.msgType = msgIdServerStatusResp;
    serverOutMessage.innerMessage.msgServerStatusResp = resp;
    msgsnd( queueIds.outputQueue, &serverOutMessage, sizeof(InnerServerOutMessage), 0 );
}
void sendingUserLogingStatus (LogingStatus logingStatus, int sessionId, MessageQueuesIds queueIds)
{
  MsgLogingResp resp;
  resp.logingStatus = logingStatus;
  resp.sessionId = sessionId;
  ServerOutMessage serverOutMessage;
  serverOutMessage.msgType = msgIdLogingResp;
  serverOutMessage.innerMessage.msgLogingResp = resp;
  msgsnd( queueIds.outputQueue, &serverOutMessage, sizeof(InnerServerOutMessage), 0 );
}
void sendingUserPlanetsList (int currentPlanetsNumber, PlanetCoordinates planets[], MessageQueuesIds queueIds)
{
  MsgGetPlanetListResp resp;
  resp.currentPlanetsNumber = currentPlanetsNumber;
  for (int i=0; i<currentPlanetsNumber;i++)
  {
    resp.planetsCoordinates [i] = planets [i];
  }
  ServerOutMessage serverOutMessage;
  serverOutMessage.msgType = msgIdGetPlanetListResp;
  serverOutMessage.innerMessage.msgGetPlanetListResp = resp;
  msgsnd( queueIds.outputQueue, &serverOutMessage, sizeof(InnerServerOutMessage), 0 );
}
void sendingPlanetInfo (bool isInfoAvaible, Resources resources, MessageQueuesIds queueIds)
{
  MsgGetPlanetInfoResp resp;
  resp.isInfoAvaible = isInfoAvaible;
  resp.resources.metal = resources.metal;
  resp.resources.crystal = resources.crystal;
  resp.resources.deuter = resources.deuter;
  ServerOutMessage serverOutMessage;
  serverOutMessage.msgType = msgIdGetPlanetInfoResp;
  serverOutMessage.innerMessage.msgGetPlanetInfoResp = resp;
  msgsnd( queueIds.outputQueue, &serverOutMessage, sizeof(InnerServerOutMessage), 0 );
}
