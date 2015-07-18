#include "tryToLoginUser.hpp"
#include "ServerInMessage.hpp"
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
#include "sendMessage.hpp"
#include "ServerOutMessage.hpp"

using namespace std;
int tryToLoginUser (string username, string pass, LogingStatus expectedResult, const MessageQueuesIds& queueIds)
{
  ServerInMessage m1;
  m1.msgType=msgIdLogingReq;
  strcpy(m1.innerMessage.msgLogingReq.userName, username.c_str());
  strcpy(m1.innerMessage.msgLogingReq.password, pass.c_str());
  sendMessage(queueIds, m1);
  ServerOutMessage logingResp; 
  msgrcv ( queueIds.inputQueue, &logingResp, sizeof(InnerServerOutMessage), 0, MSG_NOERROR );
  if (logingResp.innerMessage.msgLogingResp.logingStatus !=  expectedResult)
    {
        cout << "wrong message received: " << logingResp.innerMessage.msgLogingResp.logingStatus
	     << " expected: " << expectedResult << endl;
        exit(-1);
    }
   return logingResp.innerMessage.msgLogingResp.sessionId;
}