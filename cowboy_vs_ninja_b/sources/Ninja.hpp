/*              Ninja (inherits Cherecter.hpp) By Dana Zorohov
    ======================================================================
    For ninjas the speed parameter is set (an integer).
    The following functions are set for ninjas only:

    - move(): receives a pointer to the enemy and moves towards the enemy. 
    The ninja advances a distance equal to its speed. 

    - slash(): receives a pointer to the enemy. 
    If the ninja is alive and the enemy is less than 1 meter away, 
    the ninja will deal 40 damage to the enemy. 
    Otherwise, no damage will be done to the enemy. 

    Web source I used to get inspired:
    https://www.youtube.com/watch?v=X8nYM8wdNRE&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=26&ab_channel=TheCherno
    ======================================================================
*/

#pragma once

#include "Character.hpp"

using namespace std;

namespace ariel {


    class Ninja: public Character{
        private:
            int speed;        
        public:
            Ninja(string name, Point location, int health, int _speed);
            void slash(Character* enemy);
            void move(Character* enemy);
            
    };
}