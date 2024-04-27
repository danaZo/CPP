/*          YoungNinja (inherits Ninja.hpp) By Dana Zorohov
    ======================================================================
    move at speed 14. Generated with 100 hit points. 
    ======================================================================
*/

#include "YoungNinja.hpp"

namespace ariel {

    /*                         Constructor
    ======================================================================
    the constructor of the YoungNinja class, takes 2 parameters: 
    name (YoungNinja's name), location (YoungNinja's location)
    initializes the name and location attributes of the Ninja base 
    class by calling the Ninja constructor with the provided arguments.
    the part after the ":" invokes the base class constructor, passing the 
    name and location values to initialize the attributes.
    100 is hitPoints value - sets the initial hit points of YoungNinja to 100
    14 is the speed value 
    ======================================================================
    */

    YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location, 100,14) {}

    /*                         Constructor
    ======================================================================
    */




    /*                         print
    ======================================================================
    print N for ninja
    if alive print name, hit points and location
    if dead, print name in parentheses, and location
    ======================================================================
    */

    string YoungNinja::print() const {
        string output = "Character Type: N\n";
        
        
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