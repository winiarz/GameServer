#pragma once

const long msgIdStarSystemInfoReq = 13;
struct MsgStarSystemInfoReq
{
int sessionId;
int galaxy;
int system;
};