#include "card.hpp"

namespace ariel{
    
    Card::Card(){}

    Card::Card(std::string suit, int rank)
    {
        this->suit = suit;
        this->rank = rank;
    }
    
}