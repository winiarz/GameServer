#include "Universe.hpp"
#include <cstdlib>
#include <cstdio>
#include <ctime>

Universe::Universe () 
{
  
}
void Universe::getStarSystemInfo (int galaxy, int system, PublicPlanetInfo publicPlanetInfo[])
{
  for (int i=0;i<planetsNumber;i++)
  {
    publicPlanetInfo[i] = universe [galaxy][system][i].publicPlanetInfo;
  }
}

PlanetCoordinates Universe::randomFreePlanet (int userId)
{
  PlanetCoordinates planetCoordinates;
  while (true)
  {
    planetCoordinates.galaxy = rand() % galaxiesNumber;
    planetCoordinates.system = rand() % systemsNumber;
    planetCoordinates.planet = rand() % planetsNumber;
    if (universe [planetCoordinates.galaxy][planetCoordinates.system][planetCoordinates.planet].publicPlanetInfo.ownerUserId == -1)
    {
      universe [planetCoordinates.galaxy][planetCoordinates.system][planetCoordinates.planet].randomPlanetSize();
     universe [planetCoordinates.galaxy][planetCoordinates.system][planetCoordinates.planet].publicPlanetInfo.ownerUserId = userId;
     return planetCoordinates;
    }
  }
}
PrivatePlanetInfo Universe::getPrivatePlanetInfo (PlanetCoordinates planetCoordinates)
{
  universe[ planetCoordinates.galaxy][ planetCoordinates.system][ planetCoordinates.planet].addResources ();
  return universe[planetCoordinates.galaxy][planetCoordinates.system][planetCoordinates.planet].getPrivatePlanetInfo(); 
}
