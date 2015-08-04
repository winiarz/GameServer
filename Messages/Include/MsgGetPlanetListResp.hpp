#pragma once

int static const maxPlanetsPerUserNumber = 10;

struct PlanetCoordinates
{
int galaxy;
int system;
int planet;
};

struct MsgGetPlanetListResp
{
  int currentPlanetsNumber;
  PlanetCoordinates planetsCoordinates[maxPlanetsPerUserNumber];
};