/*                        SmartTeam class By Dana Zorohov
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

#include "SmartTeam.hpp"

namespace ariel {

    /*                         constructor
    ======================================================================
    constructor implementation for Team2
    it calls the constructor of the base class Team and passes the leader 
    to it.
    ======================================================================
    */

    SmartTeam::SmartTeam(Character* leader): Team(leader){}

    /*                         constructor
    ======================================================================
    */




    /*                         attack
    ======================================================================
    Checks of bad conditions: if the enemy_team parameter is nullptr,
    if the enemy team is not alive, if the attacking team is not alive, 
    if the attacking team's leader is not alive--> find the closest 
    character to the leader within the team by calling the ClosesestTo, 
    and update the leader to the closest character.
    if the leader is still nullptr, return without performing any attack.

    attack by iterating over the characters in the team.
    For each character (attacker) in the team:
    - Find the closest character to the attacking team's leader within the 
    enemy team
    - If the closest character is nullptr, return without attack.
    - Check if the attacker is alive. If the attacker is not alive, skip to the 
    next iteration.

    first doing for all the ninjas then cowboys.

    for a Ninja, check the distance between the attacker and the closest 
    character. If the distance is less than or equal to 1, slash the 
    closest character. Otherwise, move.

    If the attacker is a Cowboy, check if the cowboy has bullets available 
    - If the cowboy has bullets, shoot on the closest character. 
    Otherwise, reload.
    ======================================================================
    */

    void SmartTeam::attack(Team* enemy_team) {
        if (enemy_team == nullptr) {
            throw invalid_argument("Enemy team cannot be NULL");
        }
        if(!enemy_team->stillAlive()){
            throw std::runtime_error("enemy team is dead");
        }
        if(!this->stillAlive()){
            return;
        }
        
        if (!this->getLeader()->isAlive()) 
            this->setLeader(this->ClosesestTo(this->getLeader()));
        
        
        if(this->getLeader() == nullptr){return;}

        for (Character* attacker : this->getCharacters()) {
            Character* defender = enemy_team->ClosesestTo(this->getLeader());
            if(defender == nullptr){
                    return;
            }
            
            if (!attacker->isAlive()){
                continue;
            } 

            if(Ninja* ninja = dynamic_cast<Ninja*>(attacker)){
                if(ninja->distance(defender)<=1){
                    ninja->slash(defender);
                } else{
                    ninja->move(defender);
                }
            }
        }

        for (Character* attacker : this->getCharacters()) {
            Character* defender = enemy_team->ClosesestTo(this->getLeader());
            if(defender == nullptr){
                return;
            }

            if (!attacker->isAlive()){
                continue;
            } 

            if(Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker)){
                if(cowboy->hasboolets()){
                    cowboy->shoot(defender);
                } else{
                    cowboy->reload();
                }
            }
        }

        
    }

    /*                         attack
    ======================================================================
    */




    /*                         print
    ======================================================================
    first printing all the ninjas then the cowboys
    iterating over all characters in the team,
    Checking the type of the character
    ======================================================================
    */

    void SmartTeam::print() const {
        cout << "SmartTeam characters:" << endl;
        cout << "Ninjas:" << endl;
        for (const auto& character : this->getCharacters()) {
            if (dynamic_cast<Ninja*>(character)) {
                cout << character->print() << endl;
            }
        }
        cout << "Cowboys:" << endl;
        for (const auto& character : this->getCharacters()) {
            if (dynamic_cast<Cowboy*>(character)) {
                cout << character->print() << endl;
            }
        }

        
    }

    /*                         print
    ======================================================================
    */ 

}