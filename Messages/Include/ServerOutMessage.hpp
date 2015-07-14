#pragma once
#include "MsgServerStatusResp.hpp"
#include"MsgUserRegisterResp.hpp"
#include "MsgLogingResp.hpp"

union InnerServerOutMessage
{
MsgServerStatusResp msgServerStatusResp;
MsgUserRegisterResp msgUserRegisterResp;
MsgLogingResp msgLogingResp;
};


struct ServerOutMessage
{
long msgType;
InnerServerOutMessage innerMessage;
};
