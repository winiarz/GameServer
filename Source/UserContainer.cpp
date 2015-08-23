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
#include "Universe.hpp"
#include"MsgGetPlanetListResp.hpp"
UserContainer::UserContainer (): sessionIdContainer ()
{
  
}
void UserContainer::getPlanetList (int sessionId, MessageQueuesIds queueIds)
{
  if (sessionIdContainer.isUserLoged (sessionId))
  {
    int userId = sessionIdContainer.getUserId (sessionId);
    sendingUserPlanetsList (user[userId].currentPlanetsNumber, user[userId].planets, queueIds);
  }
  
}

void UserContainer::assignMotherPlanet ()
{
  Universe& universe = Universe::getUniverse();
  user[currentNumberOfUsers].planets[0] = universe.randomFreePlanet();
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
	  assignMotherPlanet ();
	  currentNumberOfUsers++;
	  sendingUserRegisterStatus (RegisterSuccessful, queueIds);
        }
}
bool  UserContainer::isRegisterPossible(char username[], MessageQueuesIds queueIds)
{
    bool possibleToRegist = true;
    if (currentNumberOfUsers == maxUsersNumber)
     {
     possibleToRegist = false;
     sendingUserRegisterStatus (TooManyUsers, queueIds);
     }
    else
    {
        for(int i=0;i<currentNumberOfUsers;i++)
        {
            if (strcmp(user[i].username, username ) == 0)
            {
            possibleToRegist = false;
            sendingUserRegisterStatus (UsernameAlreadyUsed, queueIds);
            }
        }
    }
    return possibleToRegist;
}
