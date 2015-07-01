#pragma once
#include "MsgServerStatusResp.hpp"
#include"MsgUserRegisterResp.hpp"

union InnerServerOutMessage
{
MsgServerStatusResp msgServerStatusResp;
MsgUserRegisterResp msgUserRegisterResp;
};


struct ServerOutMessage
{
long msgType;
InnerServerOutMessage innerMessage;
};
