#pragma once

#include "player.hpp"

namespace ariel{
    class Game
    {
    private:
        Player player_1;
        Player player_2;
    public:
        Game(); // empty constructor
        Game(Player player_1, Player player_2); // constructor
        
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        // void startGame();
        // Player getPlayer1();
        // Player getPlayer2();
    };
    
}