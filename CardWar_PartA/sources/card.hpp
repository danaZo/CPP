#pragma once
#include <string>

namespace ariel{

    class Card
    {
    private:
        int rank;
        std::string suit;
    
    public:
        Card();
        Card(std::string suit, int rank);
        
    };
    
}