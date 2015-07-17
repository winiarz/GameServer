#pragma once
class SessionIdContainer
{
public:
bool assignUserSessionId (int userId);
SessionIdContainer ();
int getSessionId (int userId);
private:
int static const maxSessionIds = 100;
int sessionIds[maxSessionIds];

};