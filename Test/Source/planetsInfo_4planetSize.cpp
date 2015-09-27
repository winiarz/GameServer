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
  MsgGetPlanetListResp planetList_1;
  MsgGetPlanetInfoResp planetInfo_1;
  planetList_1 = tryToGetPlanetList (sessionId_1, queueIds);
  PlanetCoordinates planetCoordinates;
  planetCoordinates = planetList_1.planetsCoordinates[0];
  planetInfo_1 = tryToGetPlanetInfo (sessionId_1, planetCoordinates, queueIds);
  if (planetInfo_1.planetSize >199 || planetInfo_1.planetSize<150)
  {
    cout << "wrong message received: " << planetInfo_1.planetSize
	     << " expected: Number from 150 to 199" << " because this is planets size" << endl;
        exit(-1);
  }
  shutdownServer (queueIds);

    return 0;
}