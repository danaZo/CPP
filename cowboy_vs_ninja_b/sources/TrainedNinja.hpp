/*              TrainedNinja (inherits Ninja.hpp) By Dana Zorohov
    ======================================================================
    move at speed 12. Generated with 120 hit points.
    ======================================================================
*/

#pragma once

#include "Ninja.hpp"

using namespace std;

namespace ariel {


    class TrainedNinja : public Ninja {
    private:
        int speed;

    public:
        TrainedNinja(std::string name, Point location);
        string print() const override;
    };


}