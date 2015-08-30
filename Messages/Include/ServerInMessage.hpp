#pragma once
#include "MsgServerControlReq.hpp"
#include "MsgServerStatusReq.hpp"
#include "MsgUserRegisterReq.hpp"
#include "MsgLogingReq.hpp"
#include "MsgGetPlanetListReq.hpp"
#include "MsgGetPlanetInfoReq.hpp"

union InnerServerInMessage
{
    MsgServerControlReq msgServerControlReq;
    MsgServerStatusReq msgServerStatusReq;
    MsgUserRegisterReq msgUserRegisterReq;
    MsgLogingReq msgLogingReq;
    MsgGetPlanetListReq msgGetPlanetListReq;
    MsgGetPlanetInfoReq msgGetPlanetInfoReq;
};

struct ServerInMessage
{
    long msgType;
    InnerServerInMessage innerMessage;
};


