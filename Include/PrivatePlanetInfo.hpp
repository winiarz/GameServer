#pragma once
#include"MsgGetPlanetInfoResp.hpp"

struct Buildings
{
  Buildings ();
  int metalMineLvl;
  int crystalMineLvl;
  int deuterMineLvl;
};


struct PrivatePlanetInfo
{
  PrivatePlanetInfo ();
  int planetSize;
  Resources resources;
  Buildings buildings;
};