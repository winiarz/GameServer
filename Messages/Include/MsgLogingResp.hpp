#pragma once
const long msgIdLogingResp = 8;

enum LogingStatus
{
     LogingSuccessful,
     InvalidUserNameOrPass
};
struct MsgLogingResp
{
LogingStatus logingStatus;
int sessionId;
};