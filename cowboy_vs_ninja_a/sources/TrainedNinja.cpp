/*          TrainedNinja (inherits Cherecter.hpp) By Dana Zorohov
    ======================================================================
    For ninjas the speed parameter is set (an integer). 
    The following functions are set for ninjas only:

    - move(): receives a pointer to the enemy and moves towards the enemy. 
      The ninja advances a distance equal to its speed. 

    - slash(): receives a pointer to the enemy. 
      If the ninja is alive and the enemy is less than 1 meter away, 
      the ninja will deal 40 damage to the enemy. 
      Otherwise, no damage will be done to the enemy.

    - TrainedNinja: move at speed 12. Generated with 120 hit points. 
    ======================================================================
*/

#include "Ninja.hpp"

namespace ariel {
    TrainedNinja::TrainedNinja(string name, Point location)
        : Character(name, location, 120), speed(12)
    {}

    void TrainedNinja::move(Character* enemy) {
       //TODO
    }

    void TrainedNinja::slash(Character* enemy) {
       //TODO
    }

    string TrainedNinja::getType() const {
        return "TrainedNinja";
    }

    string TrainedNinja::print() const {
        //TODO
        return "TrainedNinja";
    }
} 