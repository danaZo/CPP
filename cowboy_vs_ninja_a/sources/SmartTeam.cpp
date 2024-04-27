/*                        SmartTeam class By Dana Zorohov
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
     following order: TODO
     It is allowed and desirable at this stage to "ask" the other team 
     about the positions of their forces and their status as well as take 
     into account the situation of the attacking team in order to maximize 
     damage.
    ======================================================================
*/

#include "SmartTeam.hpp"

namespace ariel {

    // Constructor
    SmartTeam::SmartTeam(Character* leader){
        this->leader = leader;
        this->Characters.push_back(leader);
    }

    // Destructor
    SmartTeam::~SmartTeam(){
        for (Character* c : this->Characters){
            delete c;
        }
    }

    // Adds a character to the team
    void SmartTeam::add(Character* new_member){
        this->Characters.push_back(new_member);
    }

    void SmartTeam::attack(Team* enemy_Team) {
        //TODO
    }

    int SmartTeam::stillAlive() const {
        //TODO
        return 1;
    }

    void SmartTeam::print() const {
        //TODO
    }

}