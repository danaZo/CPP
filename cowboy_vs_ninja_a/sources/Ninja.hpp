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

/*          YoungNinja (inherits Cherecter.hpp) By Dana Zorohov
    ======================================================================
     YoungNinja: move at speed 14. Generated with 100 hit points. 
    ======================================================================
*/    
    class YoungNinja : public Character {
    private:
    int speed;

    public:
        YoungNinja(string name, Point location);

        void move(Character* enemy);
        void slash(Character* enemy);
        string getType() const override;
        string print() const override;
    };

/*          TrainedNinja (inherits Cherecter.hpp) By Dana Zorohov
    ======================================================================
    TrainedNinja: move at speed 12. Generated with 120 hit points. 
    ======================================================================
*/
    class TrainedNinja : public Character {
    private:
        int speed;

    public:
        TrainedNinja(std::string name, Point location);

        void move(Character* enemy);
        void slash(Character* enemy);
        string getType() const override;
        string print() const override;
    };

/*          OldNinja (inherits Cherecter.hpp) By Dana Zorohov
    ======================================================================
    OldNinja: move at speed 8. Spawn with 150 hit points.
    ======================================================================
*/
    class OldNinja : public Character {
    private:
        int speed;

    public:
        OldNinja(string name, Point location);

        void move(Character* enemy);
        void slash(Character* enemy);
        string getType() const override;
        string print() const override;
    };
}