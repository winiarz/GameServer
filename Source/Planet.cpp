#include "Planet.hpp"

Planet::Planet ()
{
  settled = false;
  resources.metal = 0;
  resources.crystal = 0;
  resources.deuter = 0;
}
void Planet::addResources ()
{
  resources.metal = (metalGain*secondsCounter)/3600; 
  resources.crystal = (crystalGain*secondsCounter)/3600;
  resources.deuter = (deuterGain*secondsCounter)/3600;
}