/*              Ninja (inherits Charecter.hpp) By Dana Zorohov
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

#include "Ninja.hpp"

namespace ariel {

    /*                         Constructor
    ======================================================================
    the constructor of the Ninja class, takes 4 parameters: 
    name (Ninja's name), location (Ninja's location), health (hitpoints), 
    speed
    initializes the name location and haelth attributes of the Character 
    base class by calling the Character constructor with the provided 
    arguments.
    the part after the ":" invokes the base class constructor, passing the 
    name location and health values to initialize the attributes.
    then setting the speed
    ======================================================================
    */

    Ninja::Ninja(string name, Point location, int health, int _speed)
    : Character(name, location, health), speed(_speed){}

    /*                         Constructor
    ======================================================================
    */




    /*                         slash
    ======================================================================
    checks if the enemy character is already dead. If the enemy is dead, 
    exception is thrown.
    checks if the enemy character is the same as this. If the enemy is the 
    ninja itself, exception is thrown
    checks if the ninja is already dead. If the ninja is dead, exception 
    is thrown
    checks if the ninja is alive and distance to enemy is less than 1 meter. 
    If does, the slashing action is performed. the hit method is called on 
    the enemy to reduce its hit points by 40.
    ======================================================================
    */

    void Ninja::slash(Character* enemy){
        if (!enemy->isAlive()) {
            throw std::runtime_error("Cannot slash: The enemy is already dead.");
        }
        if (enemy == this) {
            throw std::runtime_error("cant hurt itself");
        }
        if (!this->isAlive()) {
            throw std::runtime_error("Cannot slash: The Ninja itself already dead.");
        }
        if (isAlive() && distance(enemy) < 1.0) {
            enemy->hit(40);
        }   
    }

    /*                         slash
    ======================================================================
    */




    /*                         move
    ======================================================================
    using the moveTowards method of Point
    setting the ninja's location to be the closest point to the enemy's 
    location, at maximum distance of this ninja's speed
    ======================================================================
    */

    void Ninja::move(Character* enemy) {
       setLocation(Point::moveTowards(getLocation(), enemy->getLocation(), speed));
    }

    /*                         move
    ======================================================================
    */

}