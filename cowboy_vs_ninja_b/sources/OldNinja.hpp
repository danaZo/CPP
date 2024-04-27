/*              OldNinja (inherits Ninja.hpp) By Dana Zorohov
    ======================================================================
    move at speed 8. Spawn with 150 hit points.
    ======================================================================
*/

#pragma once

#include "Ninja.hpp"

using namespace std;

namespace ariel {


    class OldNinja : public Ninja {
    private:
        int speed;

    public:
        OldNinja(string name, Point location);
        string print() const override;
    };
}