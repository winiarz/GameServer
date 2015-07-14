#pragma once
#include "MsgServerControlReq.hpp"
#include "MsgServerStatusReq.hpp"
#include "MsgUserRegisterReq.hpp"
#include "MsgLogingReq.hpp"

union InnerServerInMessage
{
    MsgServerControlReq msgServerControlReq;
    MsgServerStatusReq msgServerStatusReq;
    MsgUserRegisterReq msgUserRegisterReq;
    MsgLogingReq msgLogingReq;
    
};

struct ServerInMessage
{
    long msgType;
    InnerServerInMessage innerMessage;
};


