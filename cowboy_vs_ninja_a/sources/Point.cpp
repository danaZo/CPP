/*                       Class Point By Dana Zorohov
    ======================================================================
    This class's main goal is saving positions on the game board. 
    The position is given to us as 2 double coordinates that holds the
    position of the unit along the x and y axes accordingly. 
    The Class's library supports the following operations:
    - Constructor: receives the two coordinates. 
    - Distance: receives a point and calculates the distance.  
    - Print: prints the two coordinates between brackets. 
    - moveTowards: receives source point, destination point and distance. 
      The function returns the closest point to the destination point,
      which is at most the given distance from the source point.

    * "#include <cmath>"" includes the math library, which provides the sqrt 
      function for calculating square roots.  
    ======================================================================
*/


#include "Point.hpp"
#include <cmath> // for sqrt


namespace ariel{

    /*                          Constructor
    ======================================================================
    constructor for the Point class that initializes 
    the x and y coordinates with the values received in the function.
    ======================================================================
    */

    Point::Point(double xAxes, double yAxes){
        x = xAxes;
        y = yAxes;
    }

    /*                          Constructor
    ======================================================================
    */




    /*                          distance
    ======================================================================
    A method that calculates the distance between this point and 
    other point. 
    It takes a reference to the other Point object and returns a double.
    - (x - other.x): calculates the horizontal distance between 
       this point and other point.
    - (y - other.y): calculates the vertical distance between this point 
       and other point.
    - sqrt(pow(x - other.x, 2) + pow(y - other.y, 2)): calculates the 
      Euclidean distance between the two points using the 
      Pythagorean theorem. 
    ======================================================================
    */

    double Point::distance(const Point& other) const{
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    /*                          distance
    ======================================================================
    */
}