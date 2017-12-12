#include "MyEventReceiver.hpp"
#include <iostream>

MyEventReceiver::MyEventReceiver() {
  for (irr::u32 i=0; i<irr::KEY_KEY_CODES_COUNT; ++i)
    KeyIsDown[i] = false;
}

MyEventReceiver& MyEventReceiver::operator=(const MyEventReceiver&) {
  return *this;
}

bool		MyEventReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const {
  return KeyIsDown[keyCode % irr::KEY_KEY_CODES_COUNT];
}

bool		MyEventReceiver::OnEvent(const irr::SEvent& event) {
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
      KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
  return false;
}

void MyEventReceiver::restart() {
  for (irr::u32 i=0; i<irr::KEY_KEY_CODES_COUNT; ++i)
    KeyIsDown[i] = false;
}
