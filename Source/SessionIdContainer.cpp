#include"SessionIdContainer.hpp"
#include"UserContainer.hpp"

SessionIdContainer::SessionIdContainer ()
{
  for(int i=0;i<=maxSessionIds;i++)
  {
    sessionIds[i].userId = unusedSessionId;
    sessionIds[i].timeOfAutoLogout = 0;
  }
}
int SessionIdContainer::getUserId (int sessionId)
{
  return sessionIds[sessionId].userId;
}
bool SessionIdContainer::isUserLoged (int sessionId)
{
  for(int i=0;i<=maxSessionIds;i++)
  {
    if (i == sessionId) return true;
  }
  return false;
}
int SessionIdContainer::getSessionId (int userId)
{
  for(int i=0;i<=maxSessionIds;i++)
  {
    if(sessionIds[i].userId == userId)
    {
      return i;
    }
  }
  
  return unusedSessionId;
}
bool SessionIdContainer::assignUserSessionId (int userId)
{
  if(getSessionId(userId) != unusedSessionId)
  {
    if (sessionIds[getSessionId(userId)].timeOfAutoLogout + 300 > secondsCounter)
    {
      return false;
    }
    else
    {
      sessionIds[getSessionId(userId)].timeOfAutoLogout = secondsCounter;
      return true;
    }
  }
  for(int i=0;i<=maxSessionIds;i++)
  {
    if(sessionIds[i].userId < 0)
    {
      sessionIds[i].userId = userId;
      sessionIds[i].timeOfAutoLogout = secondsCounter;
      return true;
    }
  }
  return false;
}