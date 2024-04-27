/*                        Team2.hpp By Dana Zorohov
    ======================================================================
    inherits Team.hpp
    Similar to Team.hpp except:

    - Going over all members of the team
     (for attacking, printing, or comparing) will always be done in the 
     following order: according to the order of addition without 
     distinguishing cowboys or ninjas
    ======================================================================
*/

#pragma once

#include "Team.hpp"
#include <vector>

namespace ariel {

    class Team2 : public Team {
    public:
        Team2(Character* leader);

        void attack(Team* enemy_team) override;
        void print() const ;
        
    };

}