#pragma once



struct Session
{
  int sessionId;
  int timeOfAutoLogout;
};

class SessionIdContainer
{
public:
bool assignUserSessionId (int userId);
SessionIdContainer ();
int getSessionId (int userId);
private:
int static const maxSessionIds = 100;
int static const unusedSessionId = -1;
Session sessionIds[maxSessionIds];

};