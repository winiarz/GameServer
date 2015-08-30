#pragma once
#include "InitMessageQueue.hpp"
#include"MsgUserRegisterResp.hpp"
#include"SessionIdContainer.hpp"
#include"MsgGetPlanetListResp.hpp"
#include"MsgGetPlanetInfoResp.hpp"

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
    bool isPlanetBelongingToPlayer (int userId, PlanetCoordinates planetCoordinates);
    void getPlanetInfo (int sessionId, PlanetCoordinates planetCoordinates, MessageQueuesIds queueIds);
    void getPlanetList (int sessionId, MessageQueuesIds queueIds); 
    void addUser (char username[], char password[], MessageQueuesIds queueIds);
    bool  isRegisterPossible(char username[], MessageQueuesIds queueIds);
    void loginUser (char username[], char password[], MessageQueuesIds queueIds);
    void  isLogingPossible(char username[],char password[], MessageQueuesIds queueIds);
    void assignMotherPlanet ();
    UserContainer ();
private:
    int static const maxUsersNumber = 1000;
    int currentNumberOfUsers = 0;
    SessionIdContainer sessionIdContainer;
    User user[maxUsersNumber];
};
void sendingUserRegisterStatus (UserRegisterStatus , MessageQueuesIds );
void sendingUserPlanetsList (int currentPlanetsNumber, PlanetCoordinates planets[], MessageQueuesIds queueIds);
void sendingPlanetInfo (bool isInfoAvaible, Resources resources, MessageQueuesIds queueIds);

