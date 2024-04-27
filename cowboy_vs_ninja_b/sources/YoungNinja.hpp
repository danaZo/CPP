/*              YoungNinja (inherits Ninja.hpp) By Dana Zorohov
    ======================================================================
    move at speed 14. Generated with 100 hit points. 
    ======================================================================
*/

#pragma once

#include "Ninja.hpp"

using namespace std;

namespace ariel {
 
    class YoungNinja : public Ninja {
    private:
    int speed;

    public:
        YoungNinja(string name, Point location);
        string print() const override;
    };


}