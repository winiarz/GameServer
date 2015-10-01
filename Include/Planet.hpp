#pragma once
#include"MsgGetPlanetInfoResp.hpp"
#include"UserContainer.hpp"
#include"MsgStarSystemInfoResp.hpp"
#include"PrivatePlanetInfo.hpp"



class Planet
{
public:
  Planet ();
  void addResources ();
  void randomPlanetSize();
  void addBuilding (Resources buildingCost, ObjectToBuildType objectToBuildType, MessageQueuesIds queueIds);
  PrivatePlanetInfo getPrivatePlanetInfo();
  PublicPlanetInfo publicPlanetInfo;
private:
  int lastResourceAddTime;
  PrivatePlanetInfo privatePlanetInfo;
   int static const minPlanetSize = 150; // if this get changed test will fail
   int static const maxPlanetSize = 199; // if this get changed test will fail
  int static const metalGain = 28;
  int static const crystalGain = 50;
  int static const deuterGain = 0;
};
