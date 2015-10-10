#pragma once

struct PlanetCoordinates
{
  bool operator== (const PlanetCoordinates& planetCoordinates_2) const;
  bool operator!= (const PlanetCoordinates& planetCoordinates_2) const;
  int galaxy;
  int system;
  int planet;
};