/*              Cowboy Class (inherits Cherecter.hpp) By Dana Zorohov
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

#include "Cowboy.hpp"

namespace ariel {

    Cowboy::Cowboy(const string& name, const Point& location) : Character(name, location, 110), bullets(6) {}

    void Cowboy::shoot(Character* enemy) {
        // TODO
    }

    bool Cowboy::hasBullets() const {
        return bullets > 0;
    }

    void Cowboy::reload() {
        bullets = 6;
    }

    string Cowboy::getType() const {
        return "Cowboy";
    }

    string Cowboy::print() const {
        // TODO
        return "Cowboy";
    }

}