#include "ServerInMessage.hpp"
#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
#include "sendMessage.hpp"
#include "ServerOutMessage.hpp"

using namespace std;
MsgGetPlanetInfoResp tryToGetPlanetInfo (int sessionId, PlanetCoordinates planetCoordinates,  const MessageQueuesIds& queueIds)
{
  ServerInMessage m1;
  m1.msgType=msgIdGetPlanetInfoReq;
  m1.innerMessage.msgGetPlanetInfoReq.sessionId = sessionId;
  m1.innerMessage.msgGetPlanetInfoReq.planetCoordinates =  planetCoordinates;
  sendMessage(queueIds, m1);
  ServerOutMessage PlanetInfoResp; 
  msgrcv ( queueIds.inputQueue, &PlanetInfoResp, sizeof(InnerServerOutMessage), 0, MSG_NOERROR );
  if (PlanetInfoResp.msgType != msgIdGetPlanetInfoResp)
  {
    cout << "wrong message received: " << PlanetInfoResp.msgType
	 << " expected: " << msgIdGetPlanetInfoResp << endl;
        exit(-1);
  }
  return PlanetInfoResp.innerMessage.msgGetPlanetInfoResp; 
}