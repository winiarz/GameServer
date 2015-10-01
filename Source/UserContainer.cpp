#include"UserContainer.hpp"
#include<string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include "InitMessageQueue.hpp"
#include "ServerOutMessage.hpp"
#include"MsgUserRegisterResp.hpp"
#include "SendingFunctions.hpp"
#include"SessionIdContainer.hpp"
#include"MsgGetPlanetListResp.hpp"
#include "Universe.hpp"



UserContainer::UserContainer (): sessionIdContainer ()
{
  
}
void UserContainer::placeBuildingOnPlanet (int userId, int planetIdx, PlanetCoordinates planetCoordinates,
					   ObjectToBuildType objectToBuildType, MessageQueuesIds queueIds)
{
  Universe& universe = Universe::getUniverse();
  PrivatePlanetInfo privatePlanetInfo = universe.getPrivatePlanetInfo (user[userId].planets[planetIdx]);
  Resources buildingCost;
  buildingCost = countBuildingCost (privatePlanetInfo, objectToBuildType);
  
}
Resources UserContainer::countBuildingCost (PrivatePlanetInfo privatePlanetInfo, ObjectToBuildType objectToBuildType)
{
  Resources cost;
  if (objectToBuildType == MetalMine)
  {
    long long buildingMetalCost = 1;
    long long buildingCrystalCost = 1;
    for (int i=0;i<privatePlanetInfo.buildings.metalMineLvl;i++)
    {
      buildingMetalCost = buildingMetalCost*1.2;
      buildingCrystalCost = buildingCrystalCost*1.2;
    }
    buildingMetalCost = buildingMetalCost*privatePlanetInfo.buildings.metalMineLvl*5;
    buildingCrystalCost = buildingCrystalCost*privatePlanetInfo.buildings.metalMineLvl*3;
    cost.metal = buildingMetalCost;
    cost.crystal = buildingCrystalCost;
    cost.deuter = 0;
  }
  return cost;
}
bool UserContainer::isBuildingPossible (int userId, int planetIdx, ObjectToBuildType objectToBuildType, MessageQueuesIds queueIds)
{
  if (user[userId].currentPlanetsNumber > planetIdx && planetIdx >= 0)
    {
      Universe& universe = Universe::getUniverse();
      PrivatePlanetInfo privatePlanetInfo = universe.getPrivatePlanetInfo (user[userId].planets[planetIdx]);
      Resources buildingCost;
      buildingCost = countBuildingCost (privatePlanetInfo, objectToBuildType);
      
	if (privatePlanetInfo.resources.metal >= buildingCost.metal || privatePlanetInfo.resources.crystal >= buildingCost.crystal)
	{
	  //here have to write thing that check is some building is being built currently 
	}
	else
	{
	 sendingBuildStatus (InsufficientResources,  queueIds); 
	 return false;
	}
      
    }
    else
    {
      sendingBuildStatus (WrongPlanet,  queueIds);
      return false;
    }
    return true;
}
void UserContainer::build (int sessionId, int planetIdx, ObjectToBuildType objectToBuildType, MessageQueuesIds queueIds)
{
  int userId = sessionIdContainer.getUserId (sessionId);
  if (sessionIdContainer.isUserLoged (sessionId))
  {
    if(isBuildingPossible (userId, planetIdx, objectToBuildType, queueIds))
    {
      placeBuildingOnPlanet (userId, planetIdx, user[userId].planets[planetIdx], objectToBuildType, queueIds);
    }
  }
}
void UserContainer::getStarSystemInfo (int sessionId, int galaxy, int system,  MessageQueuesIds queueIds)
{
  if (sessionIdContainer.isUserLoged (sessionId))
  {
    PublicPlanetInfo publicPlanetInfo[10]; // uwaga działa tylko na standardowym uniwersum
    Universe& universe = Universe::getUniverse();
    universe.getStarSystemInfo (galaxy, system, publicPlanetInfo);
    sendingPublicPlanetInfo (publicPlanetInfo, queueIds);
  }
}
/*
PlanetCoordinates* UserContainer::getSettledPlanetsCoordinates ()
{
  PlanetCoordinates * planetCoordinates = NULL;
 for (int i=0;i<currentNumberOfUsers;i++)
 {
   for (int j=0; i < user[i].currentPlanetsNumber;j++)
   {
      PlanetCoordinates *
   }
 }
}
*/
bool UserContainer::isPlanetBelongingToPlayer (int userId, PlanetCoordinates planetCoordinates)
{
  for (int i=0; i < user[userId].currentPlanetsNumber;i++)
  {
    if (planetCoordinates == user[userId].planets[i]) return true;
  }
 return false;
}

void UserContainer::getPlanetInfo (int sessionId, PlanetCoordinates planetCoordinates, MessageQueuesIds queueIds)
{
  if (sessionIdContainer.isUserLoged (sessionId))
  {
    int userId = sessionIdContainer.getUserId (sessionId);
    if (isPlanetBelongingToPlayer(userId, planetCoordinates) )
    {
      Universe& universe = Universe::getUniverse();
      PrivatePlanetInfo privatePlanetInfo;
      privatePlanetInfo = universe.getPrivatePlanetInfo (planetCoordinates);
      sendingPlanetInfo (true, privatePlanetInfo, queueIds);
    }
    else
    {
      PrivatePlanetInfo privatePlanetInfo;
      privatePlanetInfo.resources.metal=0;
      privatePlanetInfo.resources.crystal=0;
      privatePlanetInfo.resources.deuter=0;
      privatePlanetInfo.planetSize = -1;
      sendingPlanetInfo (false, privatePlanetInfo, queueIds);
    }
  }
}

void UserContainer::getPlanetList (int sessionId, MessageQueuesIds queueIds)
{
  if (sessionIdContainer.isUserLoged (sessionId))
  {
    int userId = sessionIdContainer.getUserId (sessionId);
    sendingUserPlanetsList (user[userId].currentPlanetsNumber, user[userId].planets, queueIds);
  }
  
}

void UserContainer::assignMotherPlanet (int userId)
{
  Universe& universe = Universe::getUniverse();
  user[currentNumberOfUsers].planets[0] = universe.randomFreePlanet(userId);
  user[currentNumberOfUsers].currentPlanetsNumber = 1; 
}

void UserContainer::loginUser (char username[], char password[], MessageQueuesIds queueIds)
{
   this -> isLogingPossible(username, password, queueIds);
}
void UserContainer::isLogingPossible(char username[],char password[], MessageQueuesIds queueIds) // tryToLogin
{
    for (int i=0;i<=currentNumberOfUsers;i++)
    {
	if (strcmp( user[i].username, username )==0)
	{
	   if (strcmp(user[i].password, password )==0)
	   {
	     if (sessionIdContainer.assignUserSessionId (i))
	     {
	       sendingUserLogingStatus (LogingSuccessful,sessionIdContainer.getSessionId (i), queueIds);
	     } 
	     else sendingUserLogingStatus (UserAlreadyLoged, -1, queueIds);
	      return;
	   }
	   else
	   {
	     sendingUserLogingStatus (InvalidUserNameOrPass, -1, queueIds);
	     return;
	   }
	}
    }
    sendingUserLogingStatus (InvalidUserNameOrPass, -1, queueIds);
    return;
}
void UserContainer::addUser (char username[], char password[], MessageQueuesIds queueIds)
{
    if ( this -> isRegisterPossible(username, queueIds) )
        {
	  strcpy (user[currentNumberOfUsers].username, username);
	  strcpy (user[currentNumberOfUsers].password, password);
	  assignMotherPlanet (currentNumberOfUsers);
	  sendingUserRegisterStatus (RegisterSuccessful, currentNumberOfUsers, queueIds);
	  currentNumberOfUsers++;
        }
}
bool  UserContainer::isRegisterPossible(char username[], MessageQueuesIds queueIds)
{
    bool possibleToRegist = true;
    if (currentNumberOfUsers == maxUsersNumber)
     {
     possibleToRegist = false;
     sendingUserRegisterStatus (TooManyUsers, -1, queueIds);
     }
    else
    {
        for(int i=0;i<currentNumberOfUsers;i++)
        {
            if (strcmp(user[i].username, username ) == 0)
            {
            possibleToRegist = false;
            sendingUserRegisterStatus (UsernameAlreadyUsed, -1, queueIds);
            }
        }
    }
    return possibleToRegist;
}
