/*                        Character Class By Dana Zorohov
    ======================================================================
    This class specifies a character. 
    A character has a location (of type Point), 
    hit points (represented by an integer) 
    and a name represented by a character string.

    * isTeamate indicates wether the character is a part of a team
      when team created with given character, this character becomes part 
      of a team, and when character is added to a team.

    Functions defined on a character:
    - isisAlive(): returns a boolean value if the character is alive 
      (is means that it has more than zero hit points) 
    
    - distance(): receives a pointer to another character and returns the 
      distance between the characters (double)

    - Hit(): gets an integer. Subtracts the appropriate amount of hit 
      points from the character. returns nothing. 

    - getName(): returns the name of the character. 

    - getLocation(): returns the location of the character. 

    - print(): prints the name of the character, the number of it's hit 
      points, and the point where the character is. 
      If the character dies, the number of hit points won't be printed, 
      and the character's name will appear in parentheses. 
      Before the name will appear a letter indicating the type of character: 
      N for ninja and C for Cowboy.
    ======================================================================
*/

#include "Character.hpp"
#include <iostream>

using namespace std;

namespace ariel {

    /*                         Constructor
    ======================================================================
    the constructor of the Character class, which takes four parameters: 
    name (character's name), location (character's location), 
    hitPoints (character's hit points), 
    and isTeamate (whether the character is a teammate or not).

    the part after the ":" is the initialization list, which initializes 
    the member variables of the class with the provided parameter values.
    ======================================================================
    */

    Character::Character(string name, Point location, int hitPoints, bool isTeamate)
            : name(name), hitPoints(hitPoints), location(location), isTeamate(isTeamate) {}  

    /*                         Constructor
    ======================================================================
    */        




    /*                         isAlive
    ======================================================================
    Check if the character is alive based on its hit points
    ======================================================================
    */

    bool Character::isAlive() const {
        return hitPoints > 0;
    }

    /*                         isAlive
    ======================================================================
    */




    /*                         distance
    ======================================================================
    Calculate the distance between the current character and 
    other character. the ditance method implemented at the Point Class.
    ======================================================================
    */

    double Character::distance(const Character* other) const {
        return location.distance(other->location);
    }

    /*                         distance
    ======================================================================
    */




    /*                         hit
    ======================================================================
    This function allows a character to receive damage or hits by reducing 
    their hit points. 
    
    The function takes an amount parameter, 
    which represents the amount of damage or hit points to be subtracted 
    from the character.

    first check if the provided amount is negative. If it is, 
    an exception of type invalid_argument is thrown. 
    This ensures that negative values are not allowed for the hit operation.

    then subtract the amount from the hitPoints variable of the character, 
    reducing the character's hit points by the specified amount.

    then check if the character's hit points have become negative after the 
    hit operation. If they have, it sets the hitPoints value to 0 to ensure 
    that the hit points cannot be negative.
    ======================================================================
    */

    void Character::hit(int amount) {
        if (amount < 0) {
            throw invalid_argument("cant hit with negative value");
        }
        hitPoints -= amount;
        if (hitPoints < 0) {
            hitPoints = 0;
        }
    }

    /*                         hit
    ======================================================================
    */




    /*                         getters and setters
    ======================================================================
    getters for: name, location, hitPoints, isTeamate
    setters for: location, isTeamate
    ======================================================================
    */

    string Character::getName() const {
        return name;
    }

    Point Character::getLocation() const {
        return location;
    }

    int Character::getHitPoints() const{
        return this->hitPoints;
    }

    void Character::setLocation(const Point& newLocation) {
        this->location = newLocation;
    }

    bool Character::getIsTeamate() const {
        return isTeamate;
    }

    void Character::setIsTeamate(bool boolToSet) {
        this->isTeamate = boolToSet;
    }

    /*                         getters and setters
    ======================================================================
    */




    /*                         print
    ======================================================================
    Prints the details of the character
    implemented differently in each character
    ======================================================================
    */

    string Character::print() const {
        return "Character";
    }

    /*                         print
    ======================================================================
    */

}