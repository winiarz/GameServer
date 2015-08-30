#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
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

int main(int argc, char* argv[])
{
  MessageQueuesIds queueIds = initMessageQueues(argc, argv);
  startServer (queueIds);
  tryToRegisterUser("winiarz", "password1", RegisterSuccessful, queueIds);
  int sessionId_1 = tryToLoginUser("winiarz", "password1", LogingSuccessful, queueIds);
  MsgGetPlanetListResp planetList_1;
  MsgGetPlanetInfoResp planetInfo_1;
  PlanetCoordinates planetCoordinates;
  planetList_1 = tryToGetPlanetList (sessionId_1, queueIds);
  planetCoordinates.galaxy = rand() % 10;// UWAGA!!!! liczby wpisane na "sztywno" jeśli rozmiar uniwersum sie zmieni test bedzie mógł failować
  planetCoordinates.system = rand() % 1000;
  planetCoordinates.planet = rand() % 10;
  int somethingWhichIsMakingLoopBelowExecute10Times = 0;
  for (int i=0;i < planetList_1.currentPlanetsNumber && somethingWhichIsMakingLoopBelowExecute10Times < 10;i++)
  {
    if (planetCoordinates == planetList_1.planetsCoordinates[i])
    {
      planetCoordinates.galaxy = rand() % 10;// UWAGA!!!! liczby wpisane na "sztywno" jeśli rozmiar uniwersum sie zmieni test bedzie mógł failować
      planetCoordinates.system = rand() % 1000;
      planetCoordinates.planet = rand() % 10;
      somethingWhichIsMakingLoopBelowExecute10Times=0;
    }
    somethingWhichIsMakingLoopBelowExecute10Times++;
  }
  planetCoordinates.galaxy = 0;
      planetCoordinates.system = 0; 
      planetCoordinates.planet = 0;
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
				       << " " << planetInfo_1.resources.deuter
	     << " expected: " <<  "all resources should be equal 0, because this planet does not belong to this user" << endl;
        exit(-1);
  }

  shutdownServer (queueIds);

    return 0;
}