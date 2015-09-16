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
#include "tryToGetPublicPlanetInfo.hpp"

int main(int argc, char* argv[])
{
  MessageQueuesIds queueIds = initMessageQueues(argc, argv);
  startServer (queueIds);
  int userId_1 = tryToRegisterUser("winiarz", "password1", RegisterSuccessful, queueIds);   
  int sessionId_1 = tryToLoginUser("winiarz", "password1", LogingSuccessful, queueIds);
  MsgGetPlanetListResp planetList_1;
  planetList_1 = tryToGetPlanetList (sessionId_1, queueIds);
  MsgStarSystemInfoResp msgStarSystemInfoResp;
  msgStarSystemInfoResp = tryToGetPublicPlanetInfo (sessionId_1, planetList_1.planetsCoordinates[0].galaxy,
						    planetList_1.planetsCoordinates[0].system, queueIds);
  if (msgStarSystemInfoResp.publicPlanetInfo[planetList_1.planetsCoordinates[0].planet].ownerUserId != userId_1)
     {
        cout << "different userId received: " << msgStarSystemInfoResp.publicPlanetInfo[planetList_1.planetsCoordinates[0].planet].ownerUserId
	     << " expected: " << userId_1 << endl;
        exit(-1);
    }
    
    msgStarSystemInfoResp = tryToGetPublicPlanetInfo (sessionId_1, (planetList_1.planetsCoordinates[0].galaxy+1) % 10,
			    (planetList_1.planetsCoordinates[0].system+1) % 1000, queueIds);
    
  for (int i=0;i<10;i++)
  {
   if (msgStarSystemInfoResp.publicPlanetInfo[i].ownerUserId != -1)
     {
        cout << "different userId received: " << msgStarSystemInfoResp.publicPlanetInfo[i].ownerUserId
	     << " expected: " << -1 << endl;
        exit(-1);
    } 
  } 
  
  shutdownServer (queueIds);

    return 0;
}