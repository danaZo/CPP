/*                        Point.hpp By Dana Zorohov
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

    * "#pragma once" is a preprocessor directive that ensures the header
      file is only included once during compilation.
    ======================================================================
*/

#pragma once

#include <iostream>

namespace ariel{
    class Point {
        private:
            double x;
            double y;
        public:
            Point(double xAxes, double yAxes);
            double distance(const Point& other) const;
    };
}