#include "ServerInMessage.hpp"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
#include "sendMessage.hpp"
#include "ServerOutMessage.hpp"

using namespace std;
MsgStarSystemInfoResp tryToGetPublicPlanetInfo (int sessionId, int galaxy, int system,  const MessageQueuesIds& queueIds)
{
  ServerInMessage m1;
  m1.msgType=msgIdStarSystemInfoReq;
  m1.innerMessage.msgStarSystemInfoReq.sessionId = sessionId;
  m1.innerMessage.msgStarSystemInfoReq.galaxy =  galaxy;
  m1.innerMessage.msgStarSystemInfoReq.system =  system;
  sendMessage(queueIds, m1);
  ServerOutMessage PlanetInfoResp; 
  msgrcv ( queueIds.inputQueue, &PlanetInfoResp, sizeof(InnerServerOutMessage), 0, MSG_NOERROR );
  if (PlanetInfoResp.msgType != msgIdStarSystemInfoResp)
  {
    cout << "wrong message received: " << PlanetInfoResp.msgType
	 << " expected: " << msgIdStarSystemInfoResp << endl;
        exit(-1);
  }
  return PlanetInfoResp.innerMessage.msgStarSystemInfoResp; 
}