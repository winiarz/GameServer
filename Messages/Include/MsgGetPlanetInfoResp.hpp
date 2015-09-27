#pragma once
const long msgIdGetPlanetInfoResp = 12;
struct Resources
{
int metal;
int crystal;
int deuter;
};
struct MsgGetPlanetInfoResp
{
bool isInfoAvaible;
Resources resources;
int planetSize;
};