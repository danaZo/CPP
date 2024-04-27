#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

#include "doctest.h"

using namespace ariel;
using namespace std;

// includes 3 checks
TEST_CASE("Point") {
    Point p1(1.0, 3.0);
    Point p2(2.0, 3.0);
    Point p3(3.0, 3.0);

    CHECK_EQ(p1.distance(p2), 1);
    CHECK_EQ(p1.distance(p3), 2);
    CHECK_EQ(p2.distance(p3), 1);

}


// includes 8 checks
TEST_CASE("Cowboy") {
    Cowboy cowboy("Bob", Point(0, 0));
    YoungNinja young_ninja("Alice", Point(0, 2));

    CHECK_EQ(cowboy.getType(), "Cowboy");

    CHECK(cowboy.hasBullets()); // 6 bullets -> should return true

    cowboy.shoot(&young_ninja); // bob shoots at alice

    CHECK_EQ(young_ninja.isAlive(), false); // alice should be dead
    CHECK_EQ(cowboy.hasBullets(), true); // bob still hove bullets

    CHECK_THROWS(cowboy.shoot(&young_ninja)); // alice is already dead, can't shoot on her
    
    YoungNinja young_ninja2("Alice2", Point(0, 3)); // new ninja to kill
    YoungNinja young_ninja3("Alice3", Point(0, 4)); // new ninja to kill
    YoungNinja young_ninja4("Alice4", Point(0, 5)); // new ninja to kill
    YoungNinja young_ninja5("Alice5", Point(0, 6)); // new ninja to kill
    
    // empty bob's stack
    cowboy.shoot(&young_ninja2);
    cowboy.shoot(&young_ninja3);
    cowboy.shoot(&young_ninja4);
    cowboy.shoot(&young_ninja5);

    YoungNinja young_ninja6("Alice6", Point(0, 6)); // new ninja to kill

    CHECK_THROWS(cowboy.shoot(&young_ninja6)); // no bullets!

    cowboy.reload(); // reload bullets, now it should be 6 again
    CHECK_EQ(cowboy.hasBullets(), true); // bob should have bullets

    
    CHECK_NOTHROW(std::cout << cowboy.print() << std::endl);
    
}


// includes 12 checks
TEST_CASE("Ninja") {
    Cowboy cowboy("Bob", Point(0, 0));
    YoungNinja youngNinja("Alice", Point(0, 2));
    TrainedNinja trainedNinja("superAlice", Point(0, 4));
    OldNinja oldNinja("MegaAlice", Point(0, 6));

    CHECK_EQ(youngNinja.getType(), "YoungNinja");
    CHECK_EQ(trainedNinja.getType(), "TrainedNinja");
    CHECK_EQ(oldNinja.getType(), "OldNinja");

    Point BobLocation = cowboy.getLocation();
    Point AliceLocation = youngNinja.getLocation();
    Point superAliceLocation = trainedNinja.getLocation();
    Point MegaAliceLocation = oldNinja.getLocation();


    CHECK_NOTHROW(youngNinja.move(&cowboy));
    CHECK_NOTHROW(trainedNinja.move(&cowboy));
    CHECK_NOTHROW(oldNinja.move(&cowboy));
    
    CHECK_NOTHROW(youngNinja.slash(&cowboy)); // kill bob
    CHECK_THROWS(trainedNinja.slash(&cowboy)); // bob should be dead
    CHECK_THROWS(oldNinja.slash(&cowboy)); // bob should be dead
        
    CHECK_NOTHROW(std::cout << youngNinja.print() << std::endl);
    CHECK_NOTHROW(std::cout << trainedNinja.print() << std::endl);
    CHECK_NOTHROW(std::cout << oldNinja.print() << std::endl);


}

// includes 8 checks
TEST_CASE("Team") {
    YoungNinja* ninja1 = new YoungNinja("Alice", Point(0, 0));
    Cowboy* cowboy1 = new Cowboy("Bob", Point(0, 1));
    OldNinja* ninja2 = new OldNinja("Alice2", Point(0, 2));
    Cowboy* cowboy2 = new Cowboy("Bob2", Point(0, 3));

    Team teamAlice(ninja1);
    Team teamBob(cowboy1);

    teamAlice.add(ninja2);
    teamBob.add(cowboy2);

    
    CHECK_EQ(teamAlice.stillAlive(), 2);
    CHECK_EQ(teamBob.stillAlive(), 2);

    YoungNinja* ninja3 = new YoungNinja("EnemyAlice", Point(5, 5));
    Cowboy* cowboy3 = new Cowboy("EnemyBob", Point(6, 6));
    
    Team enemyTeamAlice(ninja3);
    Team enemyTeamBob(cowboy3);

        
    teamAlice.attack(&enemyTeamBob);
    teamBob.attack(&enemyTeamAlice);

    CHECK_EQ(teamAlice.stillAlive(), 2); 
    CHECK_EQ(teamBob.stillAlive(), 2);
    CHECK_EQ(enemyTeamAlice.stillAlive(), 0); 
    CHECK_EQ(enemyTeamBob.stillAlive(), 0); 
    
    CHECK_NOTHROW(teamAlice.print());
    CHECK_NOTHROW(teamBob.print());
    
}

TEST_CASE("Team2") {
    YoungNinja* ninja1 = new YoungNinja("Alice", Point(0, 0));
    Cowboy* cowboy1 = new Cowboy("Bob", Point(0, 1));
    OldNinja* ninja2 = new OldNinja("Alice2", Point(0, 2));
    Cowboy* cowboy2 = new Cowboy("Bob2", Point(0, 3));

    Team2 teamAlice(ninja1);
    Team2 teamBob(cowboy1);

    teamAlice.add(ninja2);
    teamBob.add(cowboy2);

    
    CHECK_EQ(teamAlice.stillAlive(), 2);
    CHECK_EQ(teamBob.stillAlive(), 2);

    YoungNinja* ninja3 = new YoungNinja("EnemyAlice", Point(5, 5));
    Cowboy* cowboy3 = new Cowboy("EnemyBob", Point(6, 6));
    
    Team2 enemyTeamAlice(ninja3);
    Team2 enemyTeamBob(cowboy3);

        
    teamAlice.attack(&enemyTeamBob);
    teamBob.attack(&enemyTeamAlice);

    CHECK_EQ(teamAlice.stillAlive(), 2); 
    CHECK_EQ(teamBob.stillAlive(), 2);
    CHECK_EQ(enemyTeamAlice.stillAlive(), 0); 
    CHECK_EQ(enemyTeamBob.stillAlive(), 0); 
    
    CHECK_NOTHROW(teamAlice.print());
    CHECK_NOTHROW(teamBob.print());
}

TEST_CASE("SmartTeam") {
    YoungNinja* ninja1 = new YoungNinja("Alice", Point(0, 0));
    Cowboy* cowboy1 = new Cowboy("Bob", Point(0, 1));
    OldNinja* ninja2 = new OldNinja("Alice2", Point(0, 2));
    Cowboy* cowboy2 = new Cowboy("Bob2", Point(0, 3));

    SmartTeam teamAlice(ninja1);
    SmartTeam teamBob(cowboy1);

    teamAlice.add(ninja2);
    teamBob.add(cowboy2);

    
    CHECK_EQ(teamAlice.stillAlive(), 2);
    CHECK_EQ(teamBob.stillAlive(), 2);

    YoungNinja* ninja3 = new YoungNinja("EnemyAlice", Point(5, 5));
    Cowboy* cowboy3 = new Cowboy("EnemyBob", Point(6, 6));
    
    SmartTeam enemyTeamAlice(ninja3);
    SmartTeam enemyTeamBob(cowboy3);

        
    teamAlice.attack(&enemyTeamBob);
    teamBob.attack(&enemyTeamAlice);

    CHECK_EQ(teamAlice.stillAlive(), 2); 
    CHECK_EQ(teamBob.stillAlive(), 2);
    CHECK_EQ(enemyTeamAlice.stillAlive(), 0); 
    CHECK_EQ(enemyTeamBob.stillAlive(), 0); 
    
    CHECK_NOTHROW(teamAlice.print());
    CHECK_NOTHROW(teamBob.print());
}








