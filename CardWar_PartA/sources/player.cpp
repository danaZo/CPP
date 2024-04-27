#include "player.hpp"

namespace ariel {

    Player::Player(std::string player_name) // constructor
    {
        name = player_name;
    }

    Player::Player(){} // empty constructor

    int Player::stacksize(){ return 1; } //prints the amount of cards left.
    int Player::cardesTaken(){return 1; } // prints the amount of cards this player has won.
    //std::string Player::getName(){ return name;}
    //void Player::takeCard(Card c){}
}