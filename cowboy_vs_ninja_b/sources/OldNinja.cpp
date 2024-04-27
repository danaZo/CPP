/*          OldNinja Class (inherits Ninja.hpp) By Dana Zorohov
    ======================================================================
    move at speed 8. Spawn with 150 hit points.
    ======================================================================
*/

#include "OldNinja.hpp"

namespace ariel {

    /*                         Constructor
    ======================================================================
    the constructor of the OldNinja class, takes 2 parameters: 
    name (OldNinja's name), location (OldNinja's location)
    initializes the name and location attributes of the Ninja base 
    class by calling the Ninja constructor with the provided arguments.
    the part after the ":" invokes the base class constructor, passing the 
    name and location values to initialize the attributes.
    150 is hitPoints value - sets the initial hit points of OldNinja to 150
    8 is the speed value 
    ======================================================================
    */

    OldNinja::OldNinja(string name, Point location) : Ninja(name, location, 150,8) {}

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

    string OldNinja::print() const {
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