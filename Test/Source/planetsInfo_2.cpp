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
  tryToRegisterUser("mieciu", "password3", RegisterSuccessful, queueIds);
  int sessionId_1 = tryToLoginUser("winiarz", "password1", LogingSuccessful, queueIds);
  int sessionId_2 = tryToLoginUser("mieciu", "password3", LogingSuccessful, queueIds);
  MsgGetPlanetListResp planetList_1;
  MsgGetPlanetInfoResp planetInfo_1;
  PlanetCoordinates planetCoordinates;
  MsgGetPlanetListResp planetList_2;
  planetList_2 = tryToGetPlanetList (sessionId_2, queueIds);
  planetCoordinates = planetList_2.planetsCoordinates[0];
  planetInfo_1 = tryToGetPlanetInfo (sessionId_1, planetCoordinates, queueIds);
  if (planetInfo_1.isInfoAvaible == true)
  {
    cout << "wrong message received: " << planetInfo_1.isInfoAvaible
	     << " expected: " << false << " because this planet does not belong to this user" << endl;
        exit(-1);
  }
  if (planetInfo_1.resources.metal != 0 || planetInfo_1.resources.crystal != 0 || planetInfo_1.resources.deuter != 0)
  {
    cout << "wrong message received: " << planetInfo_1.resources.metal << " " << planetInfo_1.resources.crystal
				       << " " <<  planetInfo_1.resources.deuter
	     << " expected: " <<  "all resources should be equal 0, because this planet does not belong to this user" << endl;
        exit(-1);
  }
    shutdownServer (queueIds);

    return 0;
}