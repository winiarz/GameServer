#pragma once



struct Session
{
  int userId;
  int timeOfAutoLogout;
};

class SessionIdContainer
{
public:
int getUserId (int sessionId);
bool isUserLoged (int sessionId);
bool assignUserSessionId (int userId);
SessionIdContainer ();
int getSessionId (int userId);
private:
int static const maxSessionIds = 100;
int static const unusedSessionId = -1;
Session sessionIds[maxSessionIds];

};