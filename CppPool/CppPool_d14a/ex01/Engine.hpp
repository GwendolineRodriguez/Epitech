
#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <cstddef>
#include "BaseComponent.hpp"

class Engine
    : public BaseComponent
{
    public:

        Engine(float power, float x = 0, float y = 0);
        virtual ~Engine();

        void goTorward(float x, float y);
        float distanceTo(float x, float y) const;

        float getX() const;
        float getY() const;

    private:
        float _power;
        float _x;
        float _y;

};

#endif // ENGINE_HPP_
