#pragma once
const long msgIdBuildReq = 15;

enum ObjectToBuildType
{
    MetalMine
};

struct MsgBuildReq
{
int sessionId;
int planetIdx;
ObjectToBuildType objectToBuildType;
};