#include"SessionIdContainer.hpp"
SessionIdContainer::SessionIdContainer ()
{
  for(int i=0;i<=maxSessionIds;i++)
  {
    sessionIds[i] = -1;
  }
}
int SessionIdContainer::getSessionId (int userId)
{
  for(int i=0;i<=maxSessionIds;i++)
  {
    if(sessionIds[i] == userId)
    {
      return i;
    }
  }
}
bool SessionIdContainer::assignUserSessionId (int userId)
{
  for(int i=0;i<=maxSessionIds;i++)
  {
    if(sessionIds[i]==userId)
    {
      return false;
    }
  }
  for(int i=0;i<=maxSessionIds;i++)
  {
    if(sessionIds[i] < 0)
    {
      sessionIds[i] = userId;
      return true;
    }
  }
  return false;
}