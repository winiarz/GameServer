#pragma once
const long msgIdBuildResp = 16;
enum BuildStartStatus
{
   BuildStarted,
   WrongPlanet,
   InsufficientResources,
   FullBuildQueue
};

struct MsgBuildResp
{
   BuildStartStatus buildStatus;
};