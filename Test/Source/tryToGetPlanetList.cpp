#include "tryToGetPlanetList.hpp"
#include "MsgGetPlanetListResp.hpp"
#include "ServerInMessage.hpp"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
#include "sendMessage.hpp"
#include "ServerOutMessage.hpp"

using namespace std;
MsgGetPlanetListResp tryToGetPlanetList (int sessionId,  const MessageQueuesIds& queueIds)
{
  ServerInMessage m1;
  m1.msgType=msgIdGetPlanetListReq;
  m1.innerMessage.msgGetPlanetListReq.sessionId = sessionId;
  sendMessage(queueIds, m1);
  ServerOutMessage PlanetListResp; 
  msgrcv ( queueIds.inputQueue, &PlanetListResp, sizeof(InnerServerOutMessage), 0, MSG_NOERROR );
  return PlanetListResp.innerMessage.msgGetPlanetListResp; 
}