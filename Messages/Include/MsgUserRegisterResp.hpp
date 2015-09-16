#pragma once
const long msgIdUserRegisterResp = 5;

enum UserRegisterStatus
{
     RegisterSuccessful,
     UsernameAlreadyUsed,
     TooManyUsers,
     ServerNotRunning

};
struct MsgUserRegisterResp
{
UserRegisterStatus userRegisterStatus;
int  userId;
};
