#include "sources/Fraction.hpp"

#include "doctest.h"

using namespace ariel;
using namespace std;

/*  Sources I used:
    the web for the + operator tests ideas: https://www.m-math.co.il/5th-grade/fractions-adding-and-subtracting/
    the web for the - operator tests ideas: https://www.m-math.co.il/5th-grade/subtract-fractions/
    the web for the / operator tests ideas: https://he.symbolab.com/solver/fractions-divide-calculator
    the web for the * operator tests ideas: https://www.m-math.co.il/6th-grade/multiplying-fractions/
*/


// Test 1 : includes 3 CHECKS
TEST_CASE("The Denominator is not 0") {
    CHECK_THROWS(Fraction(3,0));
    CHECK_THROWS(Fraction(5,0));
    CHECK_THROWS(Fraction(8,0));
}

// Test 2 : includes 3 CHECKS
TEST_CASE("Creating new Fraction") {
   CHECK_NOTHROW(Fraction(3,5));
   CHECK_NOTHROW(Fraction(8,9));
   CHECK_NOTHROW(Fraction(51,107));
}

// Test 3 : includes 3 CHECKS
TEST_CASE("Checking the overloading of the + operator") {
   Fraction a(1,3);
   Fraction b(3,6);
   Fraction ab(5,6);
   CHECK(a+b == ab);
   Fraction a2(3,4);
   Fraction b2(3,8);
   Fraction ab2(9,8);
   CHECK(a2+b2 == ab2);
   Fraction a3(1,3);
   Fraction b3(2,4);
   Fraction ab3(5,6);
   CHECK(a3+b3 == ab3);
} 

// Test 4 : includes 4 CHECKS
TEST_CASE("Checking the overloading of the - operator") {
   Fraction a(3,4);
   Fraction b(1,4);
   Fraction ab(2,4);
   CHECK(a-b == ab);
   Fraction a2(5,7);
   Fraction b2(2,7);
   Fraction ab2(3,7);
   CHECK(a2-b2 == ab2);
   Fraction a3(1,2);
   Fraction b3(1,4);
   Fraction ab3(1,4);
   CHECK(a3-b3 == ab3);
   Fraction a4(1,4);
   Fraction b4(1,6);
   Fraction ab4(1,12);
   CHECK(a4-b4 == ab4);
}

// Test 4 : includes 4 CHECKS
TEST_CASE("Checking the overloading of the / operator") {
   Fraction a(-1,5);
   Fraction b(7,4);
   Fraction ab(-4,35);
   CHECK(a/b == ab);
   Fraction a2(1,2);
   Fraction b2(8,7);
   Fraction ab2(7,16);
   CHECK(a2/b2 == ab2);
   Fraction a3(-3,2);
   Fraction b3(-10,7);
   Fraction ab3(21,20);
   CHECK(a3/b3 == ab3);
   Fraction a4(8,7);
   Fraction b4(7,10);
   Fraction ab4(80,49);
   CHECK(a4/b4 == ab4);
}

// Test 4 : includes 4 CHECKS
TEST_CASE("Checking the overloading of the * operator") {
   Fraction a(1,2);
   Fraction b(3,4);
   Fraction ab(3,8);
   CHECK(a*b == ab);
   Fraction a2(2,3);
   Fraction b2(4,5);
   Fraction ab2(8,15);
   CHECK(a2*b2 == ab2);
   Fraction a3(3,4);
   Fraction b3(1,3);
   Fraction ab3(3,12);
   CHECK(a3*b3 == ab3);
   Fraction a4(4,5);
   Fraction b4(2,3);
   Fraction ab4(8,15);
   CHECK(a4*b4 == ab4);
}

// Test 5 : includes 1 CHECKS
TEST_CASE("Checking the overloading of the Fraction + float operator") {
   Fraction a(1,2);
   float b = 3.5;
   Fraction ab(8,2);
   CHECK(a+b == ab);
}

// Test 6 : includes 1 CHECKS
TEST_CASE("Checking the overloading of the float + Fraction operator") {
   Fraction a(1,2);
   float b = 3.5;
   Fraction ab(8,2);
   CHECK(b+a == ab);
}

// Test 7 : includes 1 CHECKS
TEST_CASE("Checking the overloading of the Fraction - float operator") {
   Fraction a(1,2);
   float b = 3.5;
   Fraction ab(6,2);
   CHECK(a-b == ab);
}

// Test 8 : includes 1 CHECKS
TEST_CASE("Checking the overloading of the float - Fraction operator") {
   Fraction a(1,2);
   float b = 3.5;
   Fraction ab(-6,2);
   CHECK(b-a == ab);
}

// Test 9 : includes 1 CHECKS
TEST_CASE("Checking the overloading of the Fraction / float operator") {
   Fraction a(1,2);
   float b = 3.5;
   Fraction ab(1,7);
   CHECK(a/b == ab);
}

// Test 10 : includes 1 CHECKS
TEST_CASE("Checking the overloading of the float / Fraction operator") {
   Fraction a(1,2);
   float b = 3.5;
   Fraction ab(7,1);
   CHECK(b/a == ab);
}

// Test 11 : includes 1 CHECKS
TEST_CASE("Checking the overloading of the float * Fraction operator") {
   Fraction a(1,2);
   float b = 3.5;
   Fraction ab(7,4);
   CHECK(b*a == ab);
}

// Test 12 : includes 1 CHECKS
TEST_CASE("Checking the overloading of the Fraction * float operator") {
   Fraction a(1,2);
   float b = 3.5;
   Fraction ab(7,4);
   CHECK(a*b == ab);
}

// Test 13 : includes 1 CHECKS
TEST_CASE("Checking the overloading of the ++ operator") {
   Fraction a(1,2);
   a++;
   Fraction app(3,2);
   CHECK(a == app);
}

// Test 14 : includes 1 CHECKS
TEST_CASE("Checking the overloading of the -- operator") {
   Fraction a(1,2);
   a--;
   Fraction app(-1,2);
   CHECK(a == app);
}

// Test 15 : includes 1 CHECKS
TEST_CASE("Checking the overloading of the >= operator") {
   Fraction a(1,2);
   Fraction b(7,4);
   CHECK(b >= a);
}

// Test 16 : includes 1 CHECKS
TEST_CASE("Checking the overloading of the > operator") {
   Fraction a(1,2);
   float b = 3.5;
   //CHECK(b > a); // not implemented yet
}
