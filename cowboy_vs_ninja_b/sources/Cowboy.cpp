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

    sources:
    https://arne-mertz.de/2015/08/new-c-features-inherited-and-delegating-constructors/
    ======================================================================
*/

#include "Cowboy.hpp"

namespace ariel {

    /*                         Constructor
    ======================================================================
    the constructor of the Cowboy class, takes 2 parameters: 
    name (cowboy's name), location (cowboy's location)
    initializes the name and location attributes of the Character base 
    class by calling the Character constructor with the provided arguments.
    the part after the ":" invokes the base class constructor, passing the 
    name and location values to initialize the attributes.
    110 is hitPoints value - sets the initial hit points of Cowboy to 110
    then setting the bullets to 6
    ======================================================================
    */

    Cowboy::Cowboy(const string& name, const Point& location) : Character(name, location, 110) {
        this->bullets = 6;
    }

    /*                         Constructor
    ======================================================================
    */

    


    /*                         getter&setter for bullets
    ======================================================================
    */

    int Cowboy::getBullets() const {
        return this->bullets;
    }

    void Cowboy::setBullets(int numBullets) {
        this->bullets = numBullets;
    }

    /*                         getter&setter for bullets
    ======================================================================
    */




    /*                         shoot
    ======================================================================
    checks if the enemy character is already dead. If the enemy is dead, 
    exception is thrown.
    checks if the enemy character is the same as this. If the enemy is the 
    cowboy itself, exception is thrown
    checks if the cowboy is already dead. If the cowboy is dead, exception 
    is thrown
    checks if the cowboy is alive and has bullets. If does, the shooting 
    action is performed. the hit method is called on the enemy to reduce its 
    hit points by 10.
    The number of bullets of the cowboy is reduced by 1 .
    ======================================================================
    */
    void Cowboy::shoot(Character* enemy) {
        if (!enemy->isAlive()) {
            throw std::runtime_error("Cannot shoot: The enemy is already dead.");
        }
        if (enemy == this) {
            throw std::runtime_error("cant hurt itself");
        }
        if (!this->isAlive()) {
            throw std::runtime_error("Cannot shoot because shooter is dead.");
        }
        if (isAlive() && hasboolets()) {
            enemy->hit(10);
            setBullets(getBullets() - 1);
        }
    }

    /*                         shoot
    ======================================================================
    */




    /*                         hasboolets
    ======================================================================
    */

    bool Cowboy::hasboolets() const {
        return this->getBullets() > 0;
    }

    /*                         hasboolets
    ======================================================================
    */




    /*                         reload
    ======================================================================
    reload with 6 new bullets
    ======================================================================
    */

    void Cowboy::reload() {
        if (!this->isAlive()) {
            throw std::runtime_error("Dead cowboy cannot reload");
        }
        this->setBullets(6);
    }

    /*                         reload
    ======================================================================
    */

    


    /*                         print
    ======================================================================
    print C for cowboy
    if alive print name, hit points and location
    if dead, print name in parentheses, and location
    ======================================================================
    */

    string Cowboy::print() const {
        
        string output = "Character Type: C\n";
        
        
        if (isAlive()) {
            output += "Character Name: " + this->getName() + "\n";
            output += "Number of hit points: " + to_string(this->getHitPoints()) + "\n";
        } else {
            output += "Character Name: (" + this->getName() + ")\n";
        }
        
        output += "Character Location: " + this->getLocation().printPoint() + "\n";
        return output;
    }

    /*                         print
    ======================================================================
    */

}