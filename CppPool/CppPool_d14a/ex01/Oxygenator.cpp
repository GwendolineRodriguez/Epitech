
#include <iostream>
#include "Errors.hpp"
#include "Oxygenator.hpp"

Oxygenator::Oxygenator()
    : _quantity(0)
{
}

void
Oxygenator::generateOxygen()
{
    _quantity += 10;
}

void
Oxygenator::useOxygen(int quantity)
{
    _quantity -= quantity;
}
