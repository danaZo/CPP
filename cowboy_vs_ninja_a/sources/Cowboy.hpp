/*              Cowboy (inherits Cherecter.hpp) By Dana Zorohov
    ======================================================================
    For cowboys, the parameter "amount of bullets" (integer) is defined. 
    A cowboy is always created with six bullets and 110 hit points. 
    The following functions are defined for cowboys only:

    - shoot(): gets a pointer to the enemy. 
      If the cowboy is not dead and has bullets left, 
      the cowboy shoots the enemy, 
      subtracting 10 hit points from the enemy, and losing 1 bullet. 
      Otherwise, no damage will be done to the enemy.

    - hasboolets(): Checking the cartridge. 
      returns a Boolean indicating whether 
      there are any bullets left in this cowboy's gun.

    - reload(): reloads the gun with six new bullets.
    ======================================================================
*/

#pragma once

#include "Character.hpp"

using namespace std;

namespace ariel {
    class Cowboy : public Character {
    private:
        int bullets;

    public:
        Cowboy(const string& name, const Point& location);

        void shoot(Character* enemy);
        bool hasBullets() const;
        void reload();
        string getType() const override;
        string print() const override;
    };
}

/*         Cowboy (inherits Cherecter.hpp) By Dana Zorohov
    ======================================================================
*/