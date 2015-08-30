#pragma once
#include"PlanetCoordinates.hpp"
const long msgIdGetPlanetInfoReq = 11;

struct MsgGetPlanetInfoReq
{
int sessionId;
PlanetCoordinates  planetCoordinates;
};