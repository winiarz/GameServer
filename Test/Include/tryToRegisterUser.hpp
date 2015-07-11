#include<string>
#include"MsgUserRegisterResp.hpp"

#include "InitMessageQueue.hpp"
using namespace std;

void tryToRegisterUser(string username, string pass, UserRegisterStatus expectedResult, const MessageQueuesIds& queueIds);

