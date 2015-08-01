#include"SessionIdContainer.hpp"
#include"UserContainer.hpp"

SessionIdContainer::SessionIdContainer ()
{
  for(int i=0;i<=maxSessionIds;i++)
  {
    sessionIds[i].sessionId = unusedSessionId;
    sessionIds[i].timeOfAutoLogout = 0;
  }
}
int SessionIdContainer::getSessionId (int userId)
{
  for(int i=0;i<=maxSessionIds;i++)
  {
    if(sessionIds[i].sessionId == userId)
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
    if(sessionIds[i].sessionId < 0)
    {
      sessionIds[i].sessionId = userId;
      sessionIds[i].timeOfAutoLogout = secondsCounter;
      return true;
    }
  }
  return false;
}