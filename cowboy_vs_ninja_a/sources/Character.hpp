/*                        Character.hpp By Dana Zorohov
    ======================================================================
    This interface specifies a character. 
    A character has a location (of type Point), 
    hit points (represented by an integer) 
    and a name represented by a character string.

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


#pragma once

#include "Point.hpp"
#include <string>

using namespace std;

namespace ariel {

    class Character {
    private:
        string name;
        int hitPoints;
        Point location;

    public:
        Character(string name, Point location, int hitPoints);
        virtual ~Character() = default;


        /* explicitly deleting the special member functions, 
          to indicate that they are not allowed to be used, 
          which prevents potential issues related to 
          object copying or moving that may arise with derived classes.
          Web source for solution:
          https://stackoverflow.com/questions/48422601/why-must-i-declare-copy-move-constructors-when-declaring-destructors
        */
        // Delete copy constructor and copy assignment operator
        Character(const Character&) = delete;
        Character& operator=(const Character&) = delete;

        // Delete move constructor and move assignment operator
        Character(Character&&) = delete;
        Character& operator=(Character&&) = delete;


        bool isAlive() const;
        double distance(const Character* other) const;
        void hit(int amount);
        string getName() const;
        Point getLocation() const;
        virtual string getType() const = 0;
        virtual string print() const;
    };

}
