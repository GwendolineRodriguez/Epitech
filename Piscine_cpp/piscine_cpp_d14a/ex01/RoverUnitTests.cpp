
#include <cassert>
#include <cstring>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"
#include "Engine.hpp"
#include "AtmosphereRegulator.hpp"
#include "Oxygenator.hpp"

void testWaterReclaimer() {
  WaterReclaimer reclaimer;
  bool hasExcept = false;

  try {
    reclaimer.start();
  } catch (MissionCriticalError const &error) {
    hasExcept = true;
    assert(error.getComponent() == "WaterReclaimer");
    assert(std::strcmp(error.what(),
        "Not enough water to achieve the mission.") == 0);
  }
  assert(hasExcept);
  for (size_t i = 0; i < 10; ++i)
    reclaimer.generateWater();
  reclaimer.start();
  hasExcept = false;
  try {
    reclaimer.generateWater();
  } catch (NasaError const &error) {
    hasExcept = true;
    assert(error.getComponent() == "WaterReclaimer");
    assert(std::strcmp(error.what(),
        "Cannot generate water, reclaimer already full.") == 0);
  }
  assert(hasExcept);

  hasExcept = false;
  try {
    reclaimer.generateWater();
  } catch (std::exception const &error) {
    hasExcept = true;
  }
  assert(hasExcept);
  hasExcept = false;
  try {
    reclaimer.generateWater();
  } catch (NasaError const &error) {
    hasExcept = true;
    assert(error.getComponent() == "WaterReclaimer");
  }
  assert(hasExcept);

  reclaimer.useWater(90);
  hasExcept = false;
  try {
    reclaimer.useWater(1);
  } catch (LifeCriticalError const &error) {
    hasExcept = true;
    assert(std::strcmp(error.what(),
        "Cannot use water, not enough in the reclaimer.") == 0);
    assert(error.getComponent() == "WaterReclaimer");
  }
  assert(hasExcept);

  hasExcept = false;
  try {
    reclaimer.useWater(-1);
  } catch (UserError const &error) {
    assert(std::strcmp(error.what(), "Water use should be positif.") == 0);
    assert(error.getComponent() == "WaterReclaimer");
    hasExcept = true;
  }
  assert(hasExcept);

  WaterReclaimer otherReclaimer;
  hasExcept = false;
  try {
    otherReclaimer.useWater(5);
  } catch (UserError const &error) {
    assert(std::strcmp(error.what(),
        "Cannot use water if the reclaimer hasn't started.") == 0);
    assert(error.getComponent() == "WaterReclaimer");
    hasExcept = true;
  }
  assert(hasExcept);

}

void testOxygenator() {
  Oxygenator oxygenator;
  bool hasExcept = false;

  try {
    oxygenator.generateOxygen();
    oxygenator.useOxygen(5);
  } catch (LifeCriticalError const &error) {
    hasExcept = true;
    assert(error.getComponent() == "Oxygenator");
    assert(std::strcmp(error.what(), "Not enough oxygen to live.") == 0);
  }
  assert(hasExcept);
  hasExcept = false;
  try {
    for (int i = 0; i < 8; ++i)
      oxygenator.generateOxygen();
    for (int i = 0; i < 8; ++i)
      oxygenator.useOxygen(10);
  } catch (MissionCriticalError const &error) {
    hasExcept = true;
    assert(error.getComponent() == "Oxygenator");
    assert(std::strcmp(error.what(),
        "Not enough oxygen to continue the mission.") == 0);
  }
  assert(hasExcept);
}

void testEngine() {
  Engine engine(3);
  bool hasExcept = false;

  try {
    engine.goTorward(10, 10);
  } catch (UserError const &error) {
    hasExcept = true;
    assert(error.getComponent() == "Engine");
    assert(std::strcmp(error.what(),
        "Cannot reach destination (10, 10).") == 0);
  }
  assert(hasExcept);
  engine.goTorward(2, 2);
  hasExcept = false;
  try {
    engine.goTorward(7, 8);
  } catch (UserError const &error) {
    hasExcept = true;
    assert(error.getComponent() == "Engine");
    assert(std::strcmp(error.what(),
        "Cannot reach destination (7, 8).") == 0);
  }
  assert(hasExcept);
  hasExcept = false;
  try {
    engine.goTorward(9, 8);
  } catch (UserError const &error) {
    hasExcept = true;
    assert(error.getComponent() == "Engine");
    assert(std::strcmp(error.what(),
        "Cannot reach destination (9, 8).") == 0);
  }
  assert(hasExcept);
  hasExcept = false;
  try {
    engine.goTorward(-10, 7);
  } catch (UserError const &error) {
    hasExcept = true;
    assert(error.getComponent() == "Engine");
    assert(std::strcmp(error.what(),
        "Cannot reach destination (-10, 7).") == 0);
  }
  assert(hasExcept);
}

void testAtmosphereRegulator() {
  bool hasExcept = false;
  try {
    AtmosphereRegulator regulator;
  } catch (NasaError const &error) {
    hasExcept = true;
    assert(error.getComponent() == "AtmosphereRegulator");
    assert(std::strcmp(error.what(), "Not implemented.") == 0);
  }
  assert(hasExcept);
}
int main() {
  testWaterReclaimer();
  testOxygenator();
  testEngine();
  testAtmosphereRegulator();
  return 0;
}
