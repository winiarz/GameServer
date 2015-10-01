#pragma once
#include"Resources.hpp"
const long msgIdGetPlanetInfoResp = 12;

struct MsgGetPlanetInfoResp
{
bool isInfoAvaible;
Resources resources;
int planetSize;
};