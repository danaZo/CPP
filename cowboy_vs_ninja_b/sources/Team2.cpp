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

#include "Team2.hpp"

namespace ariel {

    /*                         constructor
    ======================================================================
    constructor implementation for Team2
    it calls the constructor of the base class Team and passes the leader 
    to it.
    ======================================================================
    */

    Team2::Team2(Character* leader): Team(leader){}

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
    - If the attacker is a Cowboy, check if the cowboy has bullets available 
    - If the cowboy has bullets, shoot on the closest character. 
    Otherwise, reload.
    for a Ninja, check the distance between the attacker and the closest 
    character. If the distance is less than or equal to 1, slash the 
    closest character. Otherwise, move.
    ======================================================================
    */

    void Team2::attack(Team* enemy_team) {
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
            
            if(Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker)){
                
                if(cowboy->hasboolets()){
                 
                    cowboy->shoot(defender);
                }else{
                    cowboy->reload();
                }
            } 
            
            if(Ninja* ninja = dynamic_cast<Ninja*>(attacker)){
                
                if(ninja->distance(defender)<=1){
                    ninja->slash(defender);
                }else{
                    ninja->move(defender);
                }
                
            }

        }

    }

    /*                         attack
    ======================================================================
    */




    /*                         print
    ======================================================================
    iterating over all characters in the team,
    Checking the type of the character
    printing every character
    ======================================================================
    */

    void Team2::print() const {
        cout << "Team2 characters:" << endl;
 
        for (const auto& character : this->getCharacters()) {
             
            if (dynamic_cast<Cowboy*>(character)) {
                cout << "Cowboy: " << character->print() << endl;
            } else if (dynamic_cast<Ninja*>(character)) {
                cout << "Ninja: " << character->print() << endl;
            } else {
                cout << "Unknown character type" << endl;
            }
        }
    }

    /*                         print
    ======================================================================
    */

} 