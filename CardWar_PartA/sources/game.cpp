#include "game.hpp"

namespace ariel{

    // empty constructor
    Game::Game(){} 

    // constructor for the 'Game' class
    // takes 2 players as arguments
    Game::Game(Player player_1, Player player_2) 
    {
        this->player_1 = player_1;
        this->player_2 = player_2;
    }
    
    
    void Game::playTurn(){
        // TODO: implement playTurn
    }

    void Game::printLastTurn(){
        // TODO: implement printLastTurn
    }

    void Game::playAll(){
        // TODO: implement playAll
    }

    void Game::printWiner(){
        // TODO: implement printWiner
    }

    void Game::printLog(){
        // TODO: implement printLog
    }

    void Game::printStats(){
        // TODO: implement printStats
    }

   

    // void Game::startGame(){
    //     // TODO: implement startGame
    // }

    // Player Game::getPlayer1(){
    //     // TODO: implement deep copy
    //     return player_1;
    // }

    // Player Game::getPlayer2(){
    //     // TODO: implement deep copy
    //     return player_2;
    // }
};
    
  
    
    