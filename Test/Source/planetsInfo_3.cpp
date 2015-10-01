#include "PlanetCoordinates.hpp"
#include "tryToLoginUser.hpp"
#include "tryToGetPlanetList.hpp"
#include "tryToGetPlanetInfo.hpp"
#include "tryToLoginUser.hpp"
#include "tryToRegisterUser.hpp"
#include "InitMessageQueue.hpp"
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"
#include "sendMessage.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
  MessageQueuesIds queueIds = initMessageQueues(argc, argv);
  startServer (queueIds);
  tryToRegisterUser("winiarz", "password1", RegisterSuccessful, queueIds);
  int sessionId_1 = tryToLoginUser("winiarz", "password1", LogingSuccessful, queueIds);
  MsgGetPlanetListResp planetList;
  planetList = tryToGetPlanetList (sessionId_1, queueIds);
  MsgGetPlanetInfoResp planetInfo_1;
  planetInfo_1 = tryToGetPlanetInfo (sessionId_1, planetList.planetsCoordinates[0], queueIds);
  if (planetInfo_1.isInfoAvaible == false)
  {
    cout << "wrong message received: " << planetInfo_1.isInfoAvaible
	     << " expected: " << true << " because this planet belongs to this user" << endl;
        exit(-1);
  }
  if (planetInfo_1.resources.metal != 0 || planetInfo_1.resources.crystal != 0 || planetInfo_1.resources.deuter != 0)
  {
    cout << "wrong message received: " << planetInfo_1.resources.metal << " " << planetInfo_1.resources.crystal
				       << " " <<  planetInfo_1.resources.deuter
	     << " expected: " <<  "all resources should be equal 0, because time = 0" << endl;
        exit(-1);
  }
  timeElapsed(36,  queueIds);
  planetInfo_1 = tryToGetPlanetInfo (sessionId_1, planetList.planetsCoordinates[0], queueIds);
  if (planetInfo_1.isInfoAvaible == false)
  {
    cout << "wrong message received: " << planetInfo_1.isInfoAvaible
	     << " expected: " << true << " because this planet belongs to this user" << endl;
        exit(-1);
  }
  if (planetInfo_1.resources.metal != 1 || planetInfo_1.resources.crystal != 0 || planetInfo_1.resources.deuter != 0)
  {
    cout << "wrong message received: " << planetInfo_1.resources.metal << " " << planetInfo_1.resources.crystal
				       << " " <<  planetInfo_1.resources.deuter
	     << " expected: " <<  "metal should be equal 1, because time = 36" << endl;
        exit(-1);
  }
  
  timeElapsed(36,  queueIds);
  planetInfo_1 = tryToGetPlanetInfo (sessionId_1, planetList.planetsCoordinates[0], queueIds);
  if (planetInfo_1.isInfoAvaible == false)
  {
    cout << "wrong message received: " << planetInfo_1.isInfoAvaible
	     << " expected: " << true << " because this planet belongs to this user" << endl;
        exit(-1);
  }
  if (planetInfo_1.resources.metal != 2 || planetInfo_1.resources.crystal != 1 || planetInfo_1.resources.deuter != 0)
  {
    cout << "wrong message received: " << planetInfo_1.resources.metal << " " << planetInfo_1.resources.crystal
				       << " " <<  planetInfo_1.resources.deuter
	     << " expected: " <<  "metal should be equal 2 and crystal 1, because time = 72" << endl;
        exit(-1);
  }
    shutdownServer (queueIds);

    return 0;
}