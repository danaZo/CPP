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




    // Getters
    double Point::getX() const {
        return x;
    }

    double Point::getY() const {
        return y;
    }

    // Setters
    void Point::setX(double newX) {
        x = newX;
    }

    void Point::setY(double newY) {
        y = newY;
    }





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
        return sqrt(pow(this->getX() - other.getX(), 2) + pow(this->getY() - other.getY(), 2));
    }

    /*                          distance
    ======================================================================
    */




   /*                          moveTowards
    ======================================================================
    The moveTowards method takes three parameters: 
    the source point, the destination point, and the maximum distance. 
    It calculates the distance between the source and destination points 
    and checks if it is less than or equal to the maximum distance. 
    If it is, the method returns the destination point. 
    Otherwise, Calculating the line between the points:
    - subtract the x's of the source and destination points to find the 
      difference between the x's (dx), and subtract the y's to find the 
      difference between the y's (dy). 
      This gives us the vector (dx, dy) that represents the direction 
      of the line between source to destination.
    - calculating the unit vector along the line:
      divide dx and dy by the distance between the points.
      it gives us the components of a vector that represents the direction 
      and size of the line |vector(dx,dy)|. 
      By dividing these by the distance, we normalize the vector to have a 
      size of 1 (unit length). 
      This ensures that the vector represents only the direction.
      (Thanks to linear Algebra Course for this)

    - to find the point on the line that is maxDistance away from the 
      source point, we multiply the unit vector by maxDistance and add it to 
      the coordinates of the source point.
      
    Multiplying the unit vector by maxDistance scales the vector 
    to the desired length, and adding them to the source point's coordinates 
    gives us the coordinates of the point on the line that is maxDistance 
    away from the source.

    got the idea of implementation from these sources:

    https://www.khanacademy.org/computing/computer-programming/programming-natural-simulations/programming-vectors/a/vector-magnitude-normalization
    https://math.stackexchange.com/questions/2045174/how-to-find-a-point-between-two-points-with-given-distance
    https://math.stackexchange.com/questions/175896/finding-a-point-along-a-line-a-certain-distance-away-from-another-point
    Throwing invalid_argument exception when negative distance passed
    - Added it because of the student's tests - 
    ======================================================================
    */

   Point Point::moveTowards(const Point& source, const Point& destination, double MaxDistance){
        
        if (MaxDistance < 0) {
          throw std::invalid_argument("Distance can't be negative.");
      }

        double dist_between_source_dest = source.distance(destination);
        
        if (dist_between_source_dest <= MaxDistance) {
            return destination;
        }

        double dx = destination.getX() - source.getX();
        double dy = destination.getY() - source.getY();

        double unit_vecX = dx / dist_between_source_dest;
        double unit_vecY = dy / dist_between_source_dest;

        double new_pointX = source.getX() + unit_vecX * MaxDistance;
        double new_pointY = source.getY() + unit_vecY * MaxDistance;

        return Point(new_pointX, new_pointY);
    }

    /*                          moveTowards
    ======================================================================
    */




    /*                         printPoint
    ======================================================================
    A method that returns string of Point object 
    the string look like this: (x, y) 
    ======================================================================
    */

    std::string Point::printPoint() const{
        return "(" + std::to_string(this->getX()) + ", " + std::to_string(this->getY()) + ")";
    }

    /*                         printPoint
    ======================================================================
    */


}