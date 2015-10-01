#pragma once
#include "InitMessageQueue.hpp"
#include"SessionIdContainer.hpp"
#include "ServerInMessage.hpp"
#include "ServerOutMessage.hpp"
#include"PrivatePlanetInfo.hpp"



extern int secondsCounter;
struct User
{
  char username [30];
  char password [30];
  int currentPlanetsNumber;
  PlanetCoordinates planets[maxPlanetsPerUserNumber];
};

class UserContainer
{
public:
    void placeBuildingOnPlanet (int UserId, int planetIdx, PlanetCoordinates planetCoordinates,
				ObjectToBuildType objectToBuildType, MessageQueuesIds queueIds);
    Resources countBuildingCost (PrivatePlanetInfo privatePlanetInfo, ObjectToBuildType objectToBuildType);
    bool isBuildingPossible (int UserId, int planetIdx, ObjectToBuildType objectToBuildType, MessageQueuesIds queueIds);
    void build (int sessionId, int planetIdx, ObjectToBuildType objectToBuildType, MessageQueuesIds queueIds);
    void getStarSystemInfo (int sessionId, int galaxy, int system,  MessageQueuesIds queueIds);
    //PlanetCoordinates* getSettledPlanetsCoordinates ();
    bool isPlanetBelongingToPlayer (int userId, PlanetCoordinates planetCoordinates);
    void getPlanetInfo (int sessionId, PlanetCoordinates planetCoordinates, MessageQueuesIds queueIds);
    void getPlanetList (int sessionId, MessageQueuesIds queueIds); 
    void addUser (char username[], char password[], MessageQueuesIds queueIds);
    bool  isRegisterPossible(char username[], MessageQueuesIds queueIds);
    void loginUser (char username[], char password[], MessageQueuesIds queueIds);
    void  isLogingPossible(char username[],char password[], MessageQueuesIds queueIds);
    void assignMotherPlanet (int userId);
    UserContainer ();
private:
    int static const maxUsersNumber = 1000;
    int currentNumberOfUsers = 0;
    SessionIdContainer sessionIdContainer;
    User user[maxUsersNumber];
};
void sendingUserRegisterStatus (UserRegisterStatus , MessageQueuesIds );
void sendingUserPlanetsList (int currentPlanetsNumber, PlanetCoordinates planets[], MessageQueuesIds queueIds);

