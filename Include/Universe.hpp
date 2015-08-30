#pragma once
#include "Planet.hpp"
#include"MsgGetPlanetListResp.hpp"
#include"MsgGetPlanetInfoResp.hpp"
#include"PlanetCoordinates.hpp"

class Universe
{
public:
   static Universe & getUniverse()
   {
      static Universe universe;
      return universe;
   }
   PlanetCoordinates randomFreePlanet ();
   Resources getResourcesInfo (PlanetCoordinates planetCoordinates);
private:
  int static const galaxiesNumber = 10;
  int static const systemsNumber = 1000;
  int static const planetsNumber = 10;
  Planet universe[galaxiesNumber][systemsNumber][planetsNumber];
  Universe ();
  Universe (const Universe &);
};
