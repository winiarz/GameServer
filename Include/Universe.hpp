#pragma once
#include "Planet.hpp"
#include"MsgGetPlanetListResp.hpp"
class Universe
{
public:
   static Universe & getUniverse()
   {
      static Universe universe;
      return universe;
   }
   PlanetCoordinates randomFreePlanet ();
private:
  int static const galaxiesNumber = 10;
  int static const systemsNumber = 1000;
  int static const planetsNumber = 10;
  Planet universe[galaxiesNumber][systemsNumber][planetsNumber];
  Universe ();
  Universe (const Universe &);
};
