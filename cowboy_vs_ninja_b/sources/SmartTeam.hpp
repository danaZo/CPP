/*                        SmartTeam.hpp By Dana Zorohov
    ======================================================================
    inherits Team.hpp
    Similar to Team.hpp except:

    - Going over all members of the group 
     (for attacking, printing, or comparing) will always be done in the 
     following order: first go over all the ninjas, 
     then go over all the cowboys. 
     Within each team, the transition will be made according to the order 
     in which the characters were added. 
     When looking for the closest character, and two characters are at the 
     same distance, the first character that was checked between them 
     will be selected.
    ======================================================================
*/

#pragma once

#include "Team.hpp"
#include <vector>

namespace ariel {

    class SmartTeam : public Team {

    public:
        SmartTeam(Character* leader);
 
        void attack(Team* enemy_team) override;
        void print() const;
    };

}