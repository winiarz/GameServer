#include "Planet.hpp"
#include <cstdlib>
#include <cstdio>
#include <ctime>
Planet::Planet ()
{
  publicPlanetInfo.ownerUserId = -1;
  privatePlanetInfo.planetSize = -1;
  privatePlanetInfo.resources.metal = 0;
  privatePlanetInfo.resources.crystal = 0;
  privatePlanetInfo.resources.deuter = 0;
}
void Planet::addResources ()
{
  privatePlanetInfo.resources.metal = (metalGain*secondsCounter)/3600; 
  privatePlanetInfo.resources.crystal = (crystalGain*secondsCounter)/3600;
  privatePlanetInfo.resources.deuter = (deuterGain*secondsCounter)/3600;
}
void Planet::randomPlanetSize()
{
  privatePlanetInfo.planetSize = rand() % (maxPlanetSize - minPlanetSize) + minPlanetSize; 
}
PrivatePlanetInfo Planet::getPrivatePlanetInfo()
{
  return privatePlanetInfo;
}