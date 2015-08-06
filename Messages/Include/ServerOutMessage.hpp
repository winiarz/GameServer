#pragma once
#include "MsgServerStatusResp.hpp"
#include"MsgUserRegisterResp.hpp"
#include "MsgLogingResp.hpp"
#include "MsgGetPlanetListResp.hpp"

union InnerServerOutMessage
{
MsgServerStatusResp msgServerStatusResp;
MsgUserRegisterResp msgUserRegisterResp;
MsgLogingResp msgLogingResp;
MsgGetPlanetListResp msgGetPlanetListResp;
};


struct ServerOutMessage
{
long msgType;
InnerServerOutMessage innerMessage;
};
