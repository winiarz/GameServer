#include "Planet.hpp"

void sendingUserRegisterStatus (UserRegisterStatus userRegisterStatus, int userId, MessageQueuesIds queueIds);
void sendingPlanetInfo (bool isInfoAvaible, PrivatePlanetInfo privatePlanetInfo, MessageQueuesIds queueIds);
void sendingServerStatus (bool isServerRunning,  MessageQueuesIds queueIds);
void sendingUserLogingStatus (LogingStatus logingStatus, int sessionId, MessageQueuesIds queueIds);
void sendingPublicPlanetInfo (PublicPlanetInfo publicPlanetInfo[],  MessageQueuesIds queueIds);
void sendingBuildStatus (BuildStartStatus buildStatus,  MessageQueuesIds queueIds);
