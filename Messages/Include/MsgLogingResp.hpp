#pragma once
const long msgIdLogingResp = 8;

enum LogingStatus
{
     LogingSuccessful,
     InvalidUserNameOrPass,
     UserAlreadyLoged
};
struct MsgLogingResp
{
LogingStatus logingStatus;
int sessionId;
};