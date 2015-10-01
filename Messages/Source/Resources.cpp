#include"Resources.hpp"

Resources Resources::operator- (Resources resources)
{
  Resources result;
  result.metal = metal - resources.metal;
  result.crystal = crystal - resources.crystal;
  result.deuter = deuter - resources.deuter;
  return result;
}