#pragma once
#include "PlanetCoordinates.hpp"

const long msgIdGetPlanetListResp = 9;
int static const maxPlanetsPerUserNumber = 10;


struct MsgGetPlanetListResp
{
  int currentPlanetsNumber;
  PlanetCoordinates planetsCoordinates[maxPlanetsPerUserNumber];
};