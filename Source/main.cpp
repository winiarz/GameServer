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



bool isServerRunning = false;
int secondsCounter = 0;

int main(int argc, char* argv[])
{
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
                 secondsCounter++;
            }
            break;
        case msgIdServerStatusReq:
            DEBUG << "Server status req received";
            sendingServerStatus (isServerRunning, secondsCounter, queueIds);
            break;
        case msgIdUserRegisterReq:
        if (isServerRunning) userContainer.addUser(m1.innerMessage.msgUserRegisterReq.userName, m1.innerMessage.msgUserRegisterReq.password, queueIds);
            else
            {
            sendingUserRegisterStatus (ServerNotRunning, queueIds);
            }
            break;
	case msgIdLogingReq:
	    userContainer.loginUser(m1.innerMessage.msgLogingReq.userName, m1.innerMessage.msgLogingReq.password, queueIds);
            break;
        }
    }
}

