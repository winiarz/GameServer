#pragma once
#include "MsgServerControlReq.hpp"
#include "MsgServerStatusReq.hpp"
#include "MsgUserRegisterReq.hpp"
#include "MsgLogingReq.hpp"
#include "MsgGetPlanetListReq.hpp"
#include "MsgGetPlanetInfoReq.hpp"
#include "MsgStarSystemInfoReq.hpp"

union InnerServerInMessage
{
    MsgServerControlReq msgServerControlReq;
    MsgServerStatusReq msgServerStatusReq;
    MsgUserRegisterReq msgUserRegisterReq;
    MsgLogingReq msgLogingReq;
    MsgGetPlanetListReq msgGetPlanetListReq;
    MsgGetPlanetInfoReq msgGetPlanetInfoReq;
    MsgStarSystemInfoReq msgStarSystemInfoReq;
};

struct ServerInMessage
{
    long msgType;
    InnerServerInMessage innerMessage;
};


