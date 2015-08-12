#include <iostream>
#include "PlanetCoordinates.hpp"
#include "tryToLoginUser.hpp"
#include "tryToGetPlanetList.hpp"
#include "MsgGetPlanetListResp.hpp"
#include "tryToRegisterUser.hpp"
#include "InitMessageQueue.hpp"
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"
#include "sendMessage.hpp"

using namespace std;
int main(int argc, char* argv[])
{
  MessageQueuesIds queueIds = initMessageQueues(argc, argv);
    startServer (queueIds);
  tryToRegisterUser("winiarz", "password1", RegisterSuccessful, queueIds);   
  tryToRegisterUser("mieciu", "password3", RegisterSuccessful, queueIds);
  int sessionId_1 = tryToLoginUser("winiarz", "password1", LogingSuccessful, queueIds);
  int sessionId_2 = tryToLoginUser("mieciu", "password3", LogingSuccessful, queueIds);
  MsgGetPlanetListResp planetList_1;
  MsgGetPlanetListResp planetList_2;
  const int expectedResult = 1;
  planetList_1 = tryToGetPlanetList (sessionId_1, queueIds);
  planetList_2 = tryToGetPlanetList (sessionId_2, queueIds);
  if (planetList_1.currentPlanetsNumber !=  expectedResult)
    {
        cout << "wrong message received: " << planetList_1.currentPlanetsNumber
	     << " expected: " << expectedResult << endl;
        exit(-1);
    }
   if (planetList_2.currentPlanetsNumber !=  expectedResult)
    {
        cout << "wrong message received: " << planetList_2.currentPlanetsNumber
	     << " expected: " << expectedResult << endl;
        exit(-1);
    }
    if (planetList_2.planetsCoordinates[0] ==  planetList_1.planetsCoordinates[0])
    {
        cout << "same coordinates for two different planets"  << endl;
        exit(-1);
    }
    
  shutdownServer (queueIds);

    return 0;
}
