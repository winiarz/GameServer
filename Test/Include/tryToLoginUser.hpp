#include<string>
#include"MsgLogingResp.hpp"
#include "InitMessageQueue.hpp"
using namespace std;

int tryToLoginUser (string username, string pass, LogingStatus expectedResult, const MessageQueuesIds& queueIds);