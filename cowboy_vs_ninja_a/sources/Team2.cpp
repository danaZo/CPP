/*                        Team2 class By Dana Zorohov
    ======================================================================
    This class represents a group of up to 10 fighters, 
    where a fighter can be a ninja or a cowboy. 
    Each group is assigned a leader who is one of the fighters. 
    When a group is created, it gets a leader pointer. 
    
    Functions defined for a group:

    - add(): takes a pointer to a cowboy or ninja, and adds it to the group. 

    - attack(): receives a pointer to an enemy group. 
      Attacking the enemy group will be done in the following way: 
      First check if the leader of the attacking group is alive. 
      Otherwise, a new leader must be chosen, 
      who is the living character closest (in terms of location) to the 
      dead leader. Then the group will choose a victim from among the 
      enemy group. The victim is the member of the living enemy group 
      who is closest to the leader of the attacking group. 
      All living members of the attacking group will attack the chosen 
      victim. Cowboys who have bullets in their guns will shoot the victim, 
      and cowboys who don't have bullets will load their weapons. 
      Ninjas within 1 meter of the victim will kill the victim, and ninjas 
      further away will advance towards the victim. 
      At each stage, if the victim is dead, a new victim will be chosen 
      (which will be, again, the living enemy character closest to the 
      leader of the attacking group). 
      If there are no living members in the attacking group or the enemy 
      group the attack will end. 

    - stillAlive(): returns an integer number. 
      The number of members of the group that are alive. 

    - print(): goes through all the characters in the group 
      and prints their details. 

    - A destructor frees the memory allocated to all members of the group. 

    - Going over all members of the group 
     (for attacking, printing, or comparing) will always be done in the 
     following order: according to the order of addition without 
     distinguishing cowboys or ninjas
    ======================================================================
*/

#include "Team2.hpp"

namespace ariel {

    // Constructor
    Team2::Team2(Character* leader){
        this->leader = leader;
        this->Characters.push_back(leader);
    }

    // Destructor
    Team2::~Team2(){
        for (Character* c : this->Characters){
            delete c;
        }
    }

    // Adds a character to the team
    void Team2::add(Character* new_member){
        this->Characters.push_back(new_member);
    }

    void Team2::attack(Team* enemy_Team) {
        //TODO
    }

    int Team2::stillAlive() const {
        //TODO
        return 1;
    }

    void Team2::print() const {
        //TODO
    }

} 