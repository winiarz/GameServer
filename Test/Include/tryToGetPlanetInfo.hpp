#include"MsgGetPlanetListResp.hpp"
#include "InitMessageQueue.hpp"
#include"PlanetCoordinates.hpp"
#include"MsgGetPlanetInfoResp.hpp"


using namespace std;

MsgGetPlanetInfoResp tryToGetPlanetInfo (int sessionId, PlanetCoordinates planetCoordinates,  const MessageQueuesIds& queueIds);
