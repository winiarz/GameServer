#pragma once

struct PlanetCoordinates
{
  bool operator== (PlanetCoordinates& planetCoordinates_2);
  int galaxy;
  int system;
  int planet;
};