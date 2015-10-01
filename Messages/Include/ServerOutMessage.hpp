#pragma once
#include "MsgServerStatusResp.hpp"
#include"MsgUserRegisterResp.hpp"
#include "MsgLogingResp.hpp"
#include "MsgGetPlanetListResp.hpp"
#include"MsgGetPlanetInfoResp.hpp"
#include"MsgStarSystemInfoResp.hpp"
#include"MsgBuildResp.hpp"


union InnerServerOutMessage
{
MsgServerStatusResp msgServerStatusResp;
MsgUserRegisterResp msgUserRegisterResp;
MsgLogingResp msgLogingResp;
MsgGetPlanetListResp msgGetPlanetListResp;
MsgGetPlanetInfoResp msgGetPlanetInfoResp;
MsgStarSystemInfoResp  msgStarSystemInfoResp;
MsgBuildResp msgBuildResp;
};


struct ServerOutMessage
{
long msgType;
InnerServerOutMessage innerMessage;
};
