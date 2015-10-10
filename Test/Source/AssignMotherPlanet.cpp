#include "PlanetCoordinates.hpp"
#include "tryToLoginUser.hpp"
#include "tryToGetPlanetList.hpp"
#include "MsgGetPlanetListResp.hpp"
#include "tryToRegisterUser.hpp"
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"
#include "sendMessage.hpp"
#include <GameServerTestSuiteBase.hpp>

TEST_F(GameServerTestSuiteBase, AssignMotherPlaneT)
{
    startServer (queueIds);
    tryToRegisterUser("winiarz", "password1", RegisterSuccessful, queueIds);   
    tryToRegisterUser("mieciu", "password3", RegisterSuccessful, queueIds);
    int sessionId_1 = tryToLoginUser("winiarz", "password1", LogingSuccessful, queueIds);
    int sessionId_2 = tryToLoginUser("mieciu", "password3", LogingSuccessful, queueIds);
    MsgGetPlanetListResp planetList_1;
    MsgGetPlanetListResp planetList_2;
    const int expectedPlanetsNumber = 1;
    planetList_1 = tryToGetPlanetList (sessionId_1, queueIds);
    planetList_2 = tryToGetPlanetList (sessionId_2, queueIds);
    
    ASSERT_EQ(planetList_1.currentPlanetsNumber, expectedPlanetsNumber)
      << "wrong message received: " << planetList_1.currentPlanetsNumber
      << " expected: " << expectedPlanetsNumber;

    ASSERT_EQ(planetList_2.currentPlanetsNumber, expectedPlanetsNumber)
        << "wrong message received: " << planetList_2.currentPlanetsNumber
	<< " expected: " << expectedPlanetsNumber;
    
    ASSERT_NE(planetList_2.planetsCoordinates[0], planetList_1.planetsCoordinates[0])
      << "same coordinates for two different planets";
      
    shutdownServer (queueIds);
}
