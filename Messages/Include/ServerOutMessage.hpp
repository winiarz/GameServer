#pragma once
#include "MsgServerStatusResp.hpp"

union InnerServerOutMessage
{
MsgServerStatusResp msgServerStatusResp;
};


struct ServerOutMessage
{
long msgType;
InnerServerOutMessage innerMessage;
};
