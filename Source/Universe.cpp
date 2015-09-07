#include "Universe.hpp"
#include <cstdlib>
#include <cstdio>
#include <ctime>

Universe::Universe () 
{
  
}
PlanetCoordinates Universe::randomFreePlanet ()
{
  PlanetCoordinates planetCoordinates;
  while (true)
  {
    planetCoordinates.galaxy = rand() % galaxiesNumber;
    planetCoordinates.system = rand() % systemsNumber;
    planetCoordinates.planet = rand() % planetsNumber;
    if (universe [planetCoordinates.galaxy][planetCoordinates.system][planetCoordinates.planet].settled == false)
    {
     universe [planetCoordinates.galaxy][planetCoordinates.system][planetCoordinates.planet].settled = true;
     return planetCoordinates;
    }
  }
}
Resources Universe::getResourcesInfo (PlanetCoordinates planetCoordinates)
{
  universe[ planetCoordinates.galaxy][ planetCoordinates.system][ planetCoordinates.planet].addResources ();
  return universe[planetCoordinates.galaxy][planetCoordinates.system][planetCoordinates.planet].resources; 
}
