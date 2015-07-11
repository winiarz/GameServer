#include "tryToRegisterUser.hpp"
#include "ServerInMessage.hpp"
#include "sendMessage.hpp"
#include "ServerOutMessage.hpp"
#include <string.h>
#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;

void tryToRegisterUser(string username, string pass, UserRegisterStatus expectedResult, const MessageQueuesIds& queueIds)
{
    ServerInMessage m1;
    m1.msgType = msgIdUserRegisterReq;
    strcpy(m1.innerMessage.msgUserRegisterReq.userName, username.c_str());
    strcpy(m1.innerMessage.msgUserRegisterReq.password, pass.c_str());
    sendMessage(queueIds, m1);
    ServerOutMessage registerResp;
    msgrcv ( queueIds.inputQueue, &registerResp, sizeof(InnerServerOutMessage), 0, MSG_NOERROR );
    if (registerResp.innerMessage.msgUserRegisterResp.userRegisterStatus !=  expectedResult)
    {
        cout << "wrong message received: " << registerResp.innerMessage.msgUserRegisterResp.userRegisterStatus
	     << " expected: " << expectedResult << endl;
        exit(-1);
    }

}
