#pragma once
#include"MsgGetPlanetInfoResp.hpp"
#include"UserContainer.hpp"
#include"MsgStarSystemInfoResp.hpp"

struct PrivatePlanetInfo
{
  int planetSize;
  Resources resources; 
};

class Planet
{
public:
  Planet ();
  void addResources ();
  void randomPlanetSize();
  PrivatePlanetInfo getPrivatePlanetInfo();
  PublicPlanetInfo publicPlanetInfo;
private:
  PrivatePlanetInfo privatePlanetInfo;
   int static const minPlanetSize = 150; // if this get changed test will fail
   int static const maxPlanetSize = 199; // if this get changed test will fail
  int static const metalGain = 100;
  int static const crystalGain = 50;
  int static const deuterGain = 0;
};
