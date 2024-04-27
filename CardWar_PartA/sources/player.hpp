#pragma once

#include "card.hpp"

#include <string>

namespace ariel{
    class Player
    {
    private:
        std::string name;

    public:
        Player(); // empty constructor
        Player(std::string player_name); // constructor
        int stacksize(); //prints the amount of cards left.
        int cardesTaken(); // prints the amount of cards this player has won.
        //std::string getName();
        //void takeCard(Card c);
        
    };

    
}