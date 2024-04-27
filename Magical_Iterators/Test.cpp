#include "sources/MagicalContainer.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;

TEST_CASE("MagicalContainer") {
    SUBCASE("Default constructor") {
        MagicalContainer container;
        CHECK(container.size() == 0);
    }

    SUBCASE("addElement") {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(3);
        container.addElement(8);

        CHECK(container.size() == 3);
    }

    SUBCASE("removeElement") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(6);
        container.addElement(4);
        container.removeElement(5);

        CHECK(container.size() == 2);
    }

    SUBCASE("size") {
        MagicalContainer container;
        CHECK(container.size() == 0);

        container.addElement(1);
        container.addElement(2);

        CHECK(container.size() == 2);

        container.removeElement(1);

        CHECK(container.size() == 1);
    }

    SUBCASE("edge cases") {
        
        MagicalContainer container;

        CHECK(container.size() == 0);
        CHECK_THROWS(container.removeElement(1));  

        container.addElement(3);
        CHECK_THROWS(container.removeElement(10));  

        CHECK(container.size() == 1);

        for (int i = 0; i < 3000; ++i) {
            container.addElement(i);
        }

        CHECK(container.size() == 3001);  

        for (int i = 0; i < 100; ++i) {
            container.removeElement(i);
        }

        CHECK(container.size() == 2901);

        container.addElement(5);
        container.addElement(5);
        container.removeElement(5);
        CHECK_NOTHROW(container.removeElement(5));
    }
}

TEST_CASE("AscendingIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(3);
    container.addElement(6);
    
    MagicalContainer::AscendingIterator iter1(container);
    MagicalContainer::AscendingIterator iter2(container);

    CHECK_EQ(iter1,iter2);
    CHECK(!(iter1 != iter2));
    CHECK(!(iter1 > iter2));
    CHECK(!(iter1 < iter2));

    ++iter2;
    CHECK(!(iter1 == iter2));
    CHECK(iter1 != iter2);
    CHECK(iter1 < iter2);
    CHECK(iter2 > iter1);


    // MagicalContainer::AscendingIterator iter3(container);
    // CHECK_EQ(*iter3.begin(), 1);
    // CHECK_EQ(*iter3.end(), 6);


}

TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(3);
    container.addElement(6);

   
    MagicalContainer::SideCrossIterator iter1(container);
    MagicalContainer::SideCrossIterator iter2(container);

    CHECK_EQ(iter1,iter2);
    CHECK(!(iter1 != iter2));
    CHECK(!(iter1 > iter2));
    CHECK(!(iter1 < iter2));

    ++iter2;
    CHECK(!(iter1 == iter2));
    CHECK(iter1 != iter2);
    CHECK(iter1 < iter2);
    CHECK(iter2 > iter1);

    
    // MagicalContainer::SideCrossIterator iter3(container);
    // CHECK_EQ(*iter3.begin(), 1);
    // CHECK_EQ(*iter3.end(), 3);
    
}

TEST_CASE("PrimeIterator") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(5);
    container.addElement(7);

    MagicalContainer::PrimeIterator iter1(container);
    MagicalContainer::PrimeIterator iter2(container);

    CHECK_EQ(iter1,iter2);
    CHECK(!(iter1 != iter2));
    CHECK(!(iter1 > iter2));
    CHECK(!(iter1 < iter2));

    ++iter2;
    CHECK(!(iter1 == iter2));
    CHECK(iter1 != iter2);
    CHECK(iter1 < iter2);
    CHECK(iter2 > iter1);

  
    // MagicalContainer::PrimeIterator iter3(container);
    // CHECK_EQ(*iter3.begin(), 2);
    // CHECK_EQ(*iter3.end(), 7);
 
    
}

