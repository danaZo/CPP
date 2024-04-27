/*          OldNinja Class (inherits Cherecter.hpp) By Dana Zorohov
    ======================================================================
    For ninjas the speed parameter is set (an integer). 
    The following functions are set for ninjas only:

    - move(): receives a pointer to the enemy and moves towards the enemy. 
      The ninja advances a distance equal to its speed. 

    - slash(): receives a pointer to the enemy. 
      If the ninja is alive and the enemy is less than 1 meter away, 
      the ninja will deal 40 damage to the enemy. 
      Otherwise, no damage will be done to the enemy. 

    - OldNinja: move at speed 8. Spawn with 150 hit points.
    ======================================================================
*/

#include "Ninja.hpp"

namespace ariel {

OldNinja::OldNinja(string name, Point location) : Character(name, location, 150), speed(8) {}

    void OldNinja::move(Character* enemy) {
        // TODO
    }

    void OldNinja::slash(Character* enemy) {
        //TODO
    }

    string OldNinja::getType() const {
        return "OldNinja";
    }

    string OldNinja::print() const {
        // TODO
        return "OldNinja";
    }
}