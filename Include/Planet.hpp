#pragma once
#include"MsgGetPlanetInfoResp.hpp"
#include"UserContainer.hpp"


class Planet
{
public:
  Planet ();
  void addResources ();
  bool settled;
  Resources resources;
private:
  int static const metalGain = 100;
  int static const crystalGain = 50;
  int static const deuterGain = 0;
};
