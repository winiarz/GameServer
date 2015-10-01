#include "Planet.hpp"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "SendingFunctions.hpp"


Planet::Planet () 
{
  publicPlanetInfo.ownerUserId = -1;
  lastResourceAddTime = 0;
}
void Planet::addBuilding (Resources buildingCost, ObjectToBuildType objectToBuildType, MessageQueuesIds queueIds)
{
  if (objectToBuildType == MetalMine)
  {
    privatePlanetInfo.resources = privatePlanetInfo.resources - buildingCost;
    privatePlanetInfo.buildings.metalMineLvl++;// tutaj powinniśmy dopiero wstawic do kolejki budowania
    sendingBuildStatus (BuildStarted,  queueIds); 
  }
}

void Planet::addResources ()
{
  
  privatePlanetInfo.resources.metal += (metalGain* abs(secondsCounter-lastResourceAddTime) );//3600; 
  /*privatePlanetInfo.resources.crystal = privatePlanetInfo.resources.crystal +(crystalGain* abs(secondsCounter-lastResourceAddTime) )/3600;
  privatePlanetInfo.resources.deuter = privatePlanetInfo.resources.deuter + (deuterGain* abs(secondsCounter-lastResourceAddTime) )/3600;
  */

  //privatePlanetInfo.resources.metal = (metalGain*secondsCounter );
  privatePlanetInfo.resources.crystal = (crystalGain*secondsCounter)/3600;
  privatePlanetInfo.resources.deuter = (deuterGain*secondsCounter)/3600;
  lastResourceAddTime = secondsCounter;// do przerobieniaaaa całe dodawanie !!!!!!!!!
}
void Planet::randomPlanetSize()
{
  privatePlanetInfo.planetSize = rand() % (maxPlanetSize - minPlanetSize + 1) + minPlanetSize; 
}
PrivatePlanetInfo Planet::getPrivatePlanetInfo()
{
  return privatePlanetInfo;
}