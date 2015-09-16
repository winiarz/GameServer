#pragma once

const long msgIdStarSystemInfoResp = 14;

struct PublicPlanetInfo
{
  int ownerUserId;
};
struct  MsgStarSystemInfoResp
{
  PublicPlanetInfo publicPlanetInfo[10];
};