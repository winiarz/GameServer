#pragma once
#include "Planet.hpp"
#include"MsgGetPlanetListResp.hpp"
#include"MsgGetPlanetInfoResp.hpp"
#include"PlanetCoordinates.hpp"
#include"MsgStarSystemInfoResp.hpp"

class Universe
{
public:
   static Universe & getUniverse()
   {
      static Universe universe;
      return universe;
   }
   PlanetCoordinates randomFreePlanet (int userId);
   PrivatePlanetInfo getPrivatePlanetInfo (PlanetCoordinates planetCoordinates);
   void getStarSystemInfo (int galaxy, int system, PublicPlanetInfo publicPlanetInfo[]);
   void addBuilding (Resources buildingCost, PlanetCoordinates planetCoordinates, 
		     ObjectToBuildType objectToBuildType, MessageQueuesIds queueIds);
private:
  int static const galaxiesNumber = 10;
  int static const systemsNumber = 1000;
  int static const planetsNumber = 10;
  Planet universe[galaxiesNumber][systemsNumber][planetsNumber];
  Universe ();
  Universe (const Universe &);
};
