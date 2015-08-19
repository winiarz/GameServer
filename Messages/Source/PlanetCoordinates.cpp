#include "PlanetCoordinates.hpp"

bool PlanetCoordinates::operator== (PlanetCoordinates& planetCoordinates_2)
{
  return galaxy == planetCoordinates_2.galaxy && system == planetCoordinates_2.system &&
						  planet == planetCoordinates_2.planet;
 
}