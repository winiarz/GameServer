#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "ServerInMessage.hpp"
#include "InitMessageQueue.hpp"
#include "Debug.hpp"
#include "ServerOutMessage.hpp"
#include"UserContainer.hpp"
#include"SendingFunctions.hpp"
#include <cstdlib>
#include <cstdio>
#include <ctime>
int secondsCounter;

bool isServerRunning = false;

int main(int argc, char* argv[])
{
    srand( time( NULL ) );
    secondsCounter = 0;
    DEBUG << "Server start!";
    MessageQueuesIds queueIds = initMessageQueues(argc, argv);

    ServerInMessage m1;
    UserContainer userContainer;

    while (true)
    {
        int bytesReceived = msgrcv ( queueIds.inputQueue, &m1, sizeof(InnerServerInMessage), 0, MSG_NOERROR );

        if (bytesReceived != sizeof(InnerServerInMessage))
        {
            DEBUG << "error during msgrcv: " << bytesReceived;
            return -1;
        }

        switch (m1.msgType)
        {
        case msgIdServerControlReq:
            DEBUG << "Server controll received = '" << m1.innerMessage.msgServerControlReq.command << "'";
            switch (m1.innerMessage.msgServerControlReq.command)
            {
            case ServerShutdown:
                DEBUG << "Server shutdown!";
                return 0;
                break;

            case ServerRestart:
                DEBUG << "Server restart!";
                break;

            case Start:
                DEBUG << "Server start!";
                isServerRunning = true;
                break;

            case Pause:
                DEBUG << "Server is Paused!";
                isServerRunning = false;
                break;
            case SecondElapsed:
               if (isServerRunning)
		{
                 secondsCounter++;
		}
            }
            break;
        case msgIdServerStatusReq:
            DEBUG << "Server status req received";
            sendingServerStatus (isServerRunning,  queueIds);
            break;
        case msgIdUserRegisterReq:
        if (isServerRunning) userContainer.addUser(m1.innerMessage.msgUserRegisterReq.userName, m1.innerMessage.msgUserRegisterReq.password, queueIds);
            else
            {
            sendingUserRegisterStatus (ServerNotRunning, -1, queueIds);
            }
            break;
	case msgIdLogingReq:
	    userContainer.loginUser(m1.innerMessage.msgLogingReq.userName, m1.innerMessage.msgLogingReq.password, queueIds);
            break;
	case msgIdGetPlanetListReq:
	  userContainer.getPlanetList (m1.innerMessage.msgGetPlanetListReq.sessionId, queueIds);
	  break;
	 case msgIdGetPlanetInfoReq:
	   userContainer.getPlanetInfo(m1.innerMessage.msgGetPlanetInfoReq.sessionId, 
					m1.innerMessage.msgGetPlanetInfoReq.planetCoordinates, queueIds);
	  break; 
	  case msgIdStarSystemInfoReq:
	    userContainer.getStarSystemInfo (m1.innerMessage.msgStarSystemInfoReq.sessionId, 
					     m1.innerMessage.msgStarSystemInfoReq.galaxy, 
					  m1.innerMessage.msgStarSystemInfoReq.system, queueIds);
	    break;
        }
    }
}

