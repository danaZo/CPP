#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;


// Test 1 : includes 6 CHECKS
TEST_CASE("Creating a player and a game") {
    // create new player object with the name Alice
    Player p1("Alice");
    Player p2("Bob");
    // at the beggining the stack size and cards taken should be 0
    CHECK_EQ(p1.cardesTaken(), 0);
    CHECK_EQ(p1.stacksize(), 0);
    CHECK_EQ(p2.cardesTaken(), 0);
    CHECK_EQ(p2.stacksize(), 0);

    // after creating a game, each player should have same amount of cards - 26
    Game game(p1,p2);
    CHECK_EQ(p1.stacksize(), 26);
    CHECK_EQ(p2.stacksize(), 26);
}

// Test 2 : includes 5 CHECK
TEST_CASE("checking printing not throwing exeptions") {
    // create new players objects with the name Alice and Bob 
    Player p1("Alice");
    Player p2("Bob");
    // creating new game with alice and bob
    Game game(p1,p2);
    game.playTurn();
    game.playTurn();
    // should print last turn
    CHECK_NOTHROW(game.printLastTurn());
    // playes the game untill the end
    CHECK_NOTHROW(game.playAll());
    // who is the winner??? should be Alice or Bob 
    CHECK_NOTHROW(game.printWiner());
    // print the game log
    CHECK_NOTHROW(game.printLog());
    // print stats
    CHECK_NOTHROW(game.printStats());
}

// Test 3 : includes 6 CHECKS
TEST_CASE("all the cards with one player condition") {
    // create new players objects with the name Alice and Bob 
    Player p1("Alice");
    Player p2("Bob");
    // creating new game with alice and bob
    Game game(p1,p2);
    // Alice have all of them, greedy..
    CHECK(p1.stacksize() == 52);
    // Bob has nothing, very sad
    CHECK(p2.stacksize() == 0);
    // try to play but should not be possible cuz boby with zero cards
    // implementation for this condition should come later
    CHECK_NOTHROW(game.playTurn());
    // since our boby have 0 cards, he probably took 0 cards
    CHECK(p2.cardesTaken() == 0);
    // we dont need to be very smart to see that Alice is the winner
    CHECK_NOTHROW(game.printWiner());
    // try to play all but should not be possible cuz boby with zero cards
    CHECK_NOTHROW(game.playAll());
}

// Test 4 : includes 5 CHECKS
TEST_CASE("they are the same") {
    // create new players objects with the name Alice and Bob 
    Player p1("Alice");
    Player p2("Bob");
    // creating new game with alice and bob
    Game game(p1,p2);
    // Alice and Bob are equal this time
    CHECK(p1.stacksize() == 26);
    // Bob has nothing, very sad
    CHECK(p2.stacksize() == 26);
    // try to play but should not be possible cuz boby with zero cards
    // implementation for this condition should come later
    CHECK_NOTHROW(game.playTurn());
    // since our boby have 0 cards, he probably took 0 cards
    CHECK(p2.cardesTaken() == 0);
    // we dont need to be very smart to see that Alice is the winner
    CHECK_NOTHROW(game.printWiner());
}

// Test 5 : includes 5 CHECKS
TEST_CASE("last card") {
    // create new players objects with the name Alice and Bob 
    Player p1("Alice");
    Player p2("Bob");
    // creating new game with alice and bob
    Game game(p1,p2);

    // both have the last card
    CHECK_EQ(p1.stacksize(), 1);
    CHECK_EQ(p2.stacksize(), 1);

    // the last turn is up
    CHECK_NOTHROW(game.playTurn());

    // who is the winner?
    CHECK_NOTHROW(game.printWiner());

    // the game should end now - both have 0 cards in the stack
    CHECK_NOTHROW(game.playTurn());
}

// Test 6: includes 5 CHECKS
TEST_CASE("both have the same card rank - WAR") {
    // create new players objects with the name Alice and Bob 
    Player p1("Alice");
    Player p2("Bob");
    // creating new game with alice and bob
    Game game(p1,p2);

    // both have at least 3 cards
    CHECK(p1.stacksize() >= 3);
    CHECK(p2.stacksize() >= 3);

    // this turn they have same card rank
    CHECK_NOTHROW(game.playTurn());

    // should be implementation of war condition
    // for now use the playAll
    CHECK_NOTHROW(game.playAll());

    // who is the big winner?
    CHECK_NOTHROW(game.printWiner()); 
}