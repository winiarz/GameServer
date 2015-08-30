#pragma once
#include "MsgServerStatusResp.hpp"
#include"MsgUserRegisterResp.hpp"
#include "MsgLogingResp.hpp"
#include "MsgGetPlanetListResp.hpp"
#include"MsgGetPlanetInfoResp.hpp"

union InnerServerOutMessage
{
MsgServerStatusResp msgServerStatusResp;
MsgUserRegisterResp msgUserRegisterResp;
MsgLogingResp msgLogingResp;
MsgGetPlanetListResp msgGetPlanetListResp;
MsgGetPlanetInfoResp msgGetPlanetInfoResp;
};


struct ServerOutMessage
{
long msgType;
InnerServerOutMessage innerMessage;
};
