#include "Character.hpp"
#include <iostream>

using namespace std;

namespace ariel {

    Character::Character(string name, Point location, int hitPoints)
            : name(name), hitPoints(hitPoints), location(location) {}

    bool Character::isAlive() const {
        return hitPoints > 0;
    }

    double Character::distance(const Character* other) const {
        return location.distance(other->location);
    }

    void Character::hit(int amount) {
        hitPoints -= amount;
        if (hitPoints < 0) {
            hitPoints = 0;
        }
    }

    string Character::getName() const {
        return name;
    }

    Point Character::getLocation() const {
        return location;
    }

    string Character::print() const {
        //TODO
        return "Character";
    }
}