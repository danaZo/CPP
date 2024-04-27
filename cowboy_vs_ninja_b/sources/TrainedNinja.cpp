/*          TrainedNinja (inherits Ninja.hpp) By Dana Zorohov
    ======================================================================
    move at speed 12. Generated with 120 hit points. 
    ======================================================================
*/

#include "TrainedNinja.hpp"

namespace ariel {

    /*                         Constructor
    ======================================================================
    the constructor of the TrainedNinja class, takes 2 parameters: 
    name (TrainedNinja's name), location (TrainedNinja's location)
    initializes the name and location attributes of the Ninja base 
    class by calling the Ninja constructor with the provided arguments.
    the part after the ":" invokes the base class constructor, passing the 
    name and location values to initialize the attributes.
    120 is hitPoints value - sets the initial hit points of TrainedNinja 
    to 120
    12 is the speed value 
    ======================================================================
    */

    TrainedNinja::TrainedNinja(string name, Point location)
        : Ninja(name, location, 120,12)
    {}

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

    string TrainedNinja::print() const {
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