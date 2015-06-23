#pragma once
#include "MsgServerControlReq.hpp"
#include "MsgServerStatusReq.hpp"

union InnerServerInMessage
{
    MsgServerControlReq msgServerControlReq;
    MsgServerStatusReq msgServerStatusReq;
};

struct ServerInMessage
{
    long msgType;
    InnerServerInMessage innerMessage;
};


