/*                        Team.hpp By Dana Zorohov
    ======================================================================
    Represents a team of up to 10 fighters, 
    where a fighter can be a ninja or a cowboy. 
    Each team is assigned a leader who is one of the fighters. 
    When a team is created, it gets a leader pointer. 

    Members:
      vector<Character*> Characters - holds the characters of the team
      Character* leader - the leader of the team
    
    Functions defined for a team:

    - add(): takes a pointer to a cowboy or ninja, and adds it to the team. 

    - attack(): receives a pointer to an enemy team. 
      Attacking the enemy team will be done in the following way: 
      First check if the leader of the attacking team is alive. 
      Otherwise, a new leader must be chosen, 
      who is the living character closest (in terms of location) to the 
      dead leader. Then the team will choose a victim from the 
      enemy team. The victim is the member of the living enemy team 
      who is closest to the leader of the attacking team. 
      All living members of the attacking team will attack the chosen 
      victim. Cowboys who have bullets in their guns will shoot the victim, 
      and cowboys who don't have bullets will load their weapons. 
      Ninjas within 1 meter of the victim will kill the victim, and ninjas 
      further away will advance towards the victim. 
      At each stage, if the victim is dead, a new victim will be chosen 
      (which will be, again, the living enemy character closest to the 
      leader of the attacking team). 
      If there are no living members in the attacking team or the enemy 
      team the attack will end. 

    - stillAlive(): returns an integer number. 
      The number of members of the team that are alive. 

    - print(): goes through all the characters in the team 
      and prints their details. 

    - A destructor frees the memory allocated to all members of the team. 

    - Going over all members of the team 
     (for attacking, printing, or comparing) will always be done in the 
     following order: first go over all the cowboys, 
     then go over all the ninjas. 
     Within each team, the transition will be made according to the order 
     in which the characters were added. 
     When looking for the closest character, and two characters are at the 
     same distance, the first character that was checked between them 
     will be selected.
    ======================================================================
*/

#include "Team.hpp"
#include <limits> // for attack

namespace ariel {

    /*                         constructor
    ======================================================================
    initializes a new Team object with a specified leader.
    first check if the leader character is already a member of another team. 
    if it does, an exception of type runtime_error is thrown 

    then assign the leader to be the leader received, 
    setting isteamate to true, adding the leader to the Characters vector, 
    which represents the members of the team.
    ======================================================================
    */

    Team::Team(Character* leader_){
        if (leader_->getIsTeamate()) {
            throw runtime_error("The captain is already a member of another team");
        }
        this->leader = leader_;
        leader->setIsTeamate(true);  // Set isTeamate to true for the leader character
        this->Characters.push_back(leader);
        
        
    }

     /*                         constructor
    ======================================================================
    */





    /*                         default constructor
    ======================================================================
    */

    Team::Team(){}

    /*                         default constructor
    ======================================================================
    */





    /*                         destructor
    ======================================================================
    going over all the characters and delete each one
    ======================================================================
    */

    Team::~Team(){
        for (Character* c : this->Characters){
            delete c;
        }
    }

    /*                         destructor
    ======================================================================
    */


    

    /*                         add
    ======================================================================
    first checks: that the size is not 10 cuz this is the max size of team
    that the new member is not in another team
    then adding the new member to the characters vector of this team
    and setting the flag that this new member is a teamate
    ======================================================================
    */

    void Team::add(Character* new_member){
        if (this->Characters.size() >= 10) {
            throw runtime_error("A team can have at most 10 teammates");
        }

        if (new_member->getIsTeamate()) {
            throw runtime_error("The character is already a member of another team");
        }
        this->Characters.push_back(new_member);
        new_member->setIsTeamate(true);  // Set isTeamate to true for the teamate character
        
    }

    /*                         add
    ======================================================================
    */




    /*                         stillAlive
    ======================================================================
    Returns the number of alive characters in the team
    going over all the charcters checks if each is alive and counts the 
    living characters
    ======================================================================
    */
    
    int Team::stillAlive() const{
        
        int count = 0;
        for (Character* c : this->getCharacters()){
            if (c->isAlive()){
                count++;
            }
        }
        
        return count;
    }

    /*                         stillAlive
    ======================================================================
    */

    


    /*                         print
    ======================================================================
    first printing all the cowboys then the ninjas
    iterating over all characters in the team,
    Checking the type of the character
    ======================================================================
    */

    void Team::print() const{
        cout << "Team characters:" << endl;
        cout << "Cowboys:" << endl;
        for (const auto& character : Characters) {
            if (dynamic_cast<Cowboy*>(character)) {
                cout << character->print() << endl;
            }
        }

        cout << "Ninjas:" << endl;
        for (const auto& character : Characters) {
            if (dynamic_cast<Ninja*>(character)) {
                cout << character->print() << endl;
            }
        }
    } 

    /*                         print
    ======================================================================
    */  




    /*                         ClosesestTo
    ======================================================================
    finding the character in the team that is closest to a given 
    target character.

    new_ represents the closest character.

    first initialize the min_distance variable to the maximum value 
    possible. This value is obtained from the numeric_limits<double>::max(), 
    which returns the maximum representable value for a double type. 
    This ensures that the initial minimum distance is set to a value that 
    will be overwritten during the loop.

    then initialize the new_ to nullptr. 
    iterate over each character in the Characters vector of the team.
    check if the character is alive, if the character is dead, skip it and 
    continue to the next iteration.

    Calculate the distance between the target and the current
    Compare the calculated distance with the current minimum distance.

    if the calculated distance is less than the minimum distance, update the 
    minimum distance to the calculated distance and update the new_ pointer to 
    point to the current.

    repeat for all the characters in the team.

    after iterating over all the characters, return the new_ pointer
    ======================================================================
    */

    Character* Team::ClosesestTo(Character* target){
            double min_distance = numeric_limits<double>::max();
            Character* new_ = nullptr;
            for (Character* c : this->Characters) {
                if (c->isAlive()) {
                    double distance = target->distance(c);
                    if (distance < min_distance) {
                        min_distance = distance;
                        new_ = c;
                    }
                }
            }
        return new_;
    }

    /*                         ClosesestTo
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

    first doing for all the cowboys then ninjas.
    
    for a Ninja, check the distance between the attacker and the closest 
    character. If the distance is less than or equal to 1, slash the 
    closest character. Otherwise, move.
    ======================================================================
    */

    void Team::attack(Team* enemy_team){
        if (enemy_team == nullptr) {
            throw invalid_argument("Enemy team cannot be NULL");
        }
        if(!enemy_team->stillAlive()){
            throw std::runtime_error("enemy team is dead");
        }
        if(!this->stillAlive()){
            return;
        }
        
        if (!this->leader->isAlive()) 
            this->leader = this->ClosesestTo(this->leader);
        
        if(leader == nullptr){
            return;
        }
        
        for (Character* attacker : Characters) {
            Character* defender = enemy_team->ClosesestTo(this->leader);
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

        for (Character* attacker : Characters) {
            Character* defender = enemy_team->ClosesestTo(this->leader);
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

    }

    /*                         attack
    ======================================================================
    */




    /*                         getters & setters
    ======================================================================
    */
    Character* Team::getLeader() const{
        return this->leader;
    }

    void Team::setLeader(Character* new_leader) {
       
        this->leader = new_leader;
    }

    const vector<Character*>& Team::getCharacters() const{
        return Characters;
    }

    /*                         getters & setters
    ======================================================================
    */

}