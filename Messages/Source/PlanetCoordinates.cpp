#include "PlanetCoordinates.hpp"

bool PlanetCoordinates::operator== (const PlanetCoordinates& planetCoordinates_2) const
{
  return galaxy == planetCoordinates_2.galaxy && system == planetCoordinates_2.system &&
						  planet == planetCoordinates_2.planet;
 
}

bool PlanetCoordinates::operator!= (const PlanetCoordinates& planetCoordinates_2) const
{
  return galaxy != planetCoordinates_2.galaxy ||
         system != planetCoordinates_2.system ||
	 planet != planetCoordinates_2.planet;
 
}