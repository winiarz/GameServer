#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;
#include "ServerInMessage.hpp"
#include "InitMessageQueue.hpp"
#include "Debug.hpp"
#include "ServerOutMessage.hpp"

bool isServerRunning = false;
int secondsCounter = 0;

int main(int argc, char* argv[])
{
    DEBUG << "Server start!";
    MessageQueuesIds queueIds = initMessageQueues(argc, argv);

    ServerInMessage m1;

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
        case msgServerStatusReq:
            DEBUG << "Server status req received";
            MsgServerStatusResp resp;
            resp.isServerRunning = isServerRunning;
            resp.secondsCounter = secondsCounter;
            
            ServerOutMessage serverOutMessage;
            serverOutMessage.msgType = msgServerStatusResp;
            serverOutMessage.innerMessage.msgServerStatusResp = resp;

            msgsnd( queueIds.outputQueue, &serverOutMessage, sizeof(InnerServerOutMessage), 0 );
            break;
        }
    }
}

