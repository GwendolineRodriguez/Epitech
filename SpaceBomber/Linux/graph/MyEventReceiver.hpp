#ifndef MYEVENTRECEIVER_HPP
#define MYEVENTRECEIVER_HPP

#include "irrlicht-1.8.3/include/irrlicht.h"

class MyEventReceiver : public irr::IEventReceiver {
  bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];

public:

  // This is the one method that we have to implement
  virtual bool OnEvent(const irr::SEvent& event);
  virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;

  MyEventReceiver();
  void restart();
  MyEventReceiver& operator=(const MyEventReceiver&);
};

#endif
