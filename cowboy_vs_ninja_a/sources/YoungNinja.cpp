/*          YoungNinja (inherits Cherecter.hpp) By Dana Zorohov
    ======================================================================
    For ninjas the speed parameter is set (an integer).
    The following functions are set for ninjas only:

    - move(): receives a pointer to the enemy and moves towards the enemy. 
    The ninja advances a distance equal to its speed. 

    - slash(): receives a pointer to the enemy. 
    If the ninja is alive and the enemy is less than 1 meter away, 
    the ninja will deal 40 damage to the enemy. 
    Otherwise, no damage will be done to the enemy.

    - YoungNinja: move at speed 14. Generated with 100 hit points. 
    ======================================================================
*/

#include "Ninja.hpp"

namespace ariel {

    YoungNinja::YoungNinja(string name, Point location) : Character(name, location, 100), speed(14) {}

    void YoungNinja::move(Character* enemy) {
       // TODO
    }

    void YoungNinja::slash(Character* enemy) {
        //TODO
    }

    string YoungNinja::getType() const {
        return "YoungNinja";
    }

    string YoungNinja::print() const {
        //TODO
        return "YoungNinja";
    }
}