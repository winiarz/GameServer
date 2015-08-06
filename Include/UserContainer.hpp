#pragma once
#include "InitMessageQueue.hpp"
#include"MsgUserRegisterResp.hpp"
#include"SessionIdContainer.hpp"
#include"MsgGetPlanetListResp.hpp"

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
    void getPlanetList (int sessionId, MessageQueuesIds queueIds); 
    void addUser (char username[], char password[], MessageQueuesIds queueIds);
    bool  isRegisterPossible(char username[], MessageQueuesIds queueIds);
    void loginUser (char username[], char password[], MessageQueuesIds queueIds);
    void  isLogingPossible(char username[],char password[], MessageQueuesIds queueIds);
    void assignMotherPlanet ();
    UserContainer ();
private:
    int static const maxUsersNumber = 100;
    int currentNumberOfUsers = 0;
    SessionIdContainer sessionIdContainer;
    User user[maxUsersNumber];
};
void sendingUserRegisterStatus (UserRegisterStatus , MessageQueuesIds );
void sendingUserPlanetsList (int currentPlanetsNumber, PlanetCoordinates planets[], MessageQueuesIds queueIds);
