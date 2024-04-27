#include "Fraction.hpp"

#include <cmath> // for round

namespace ariel {

    // implementation of the constructor
    Fraction::Fraction(int numer, int denomi){
        this->numerator = numer;
        this->denominator = denomi;
    }

    // numerator getter
    int Fraction::getNumer() const{
        return this->numerator;
    }

    // numerator setter
    void Fraction::setNumer(int n){
        this->numerator = n;
    }

    // denominator getter
    int Fraction::getDenomi() const{
        return this->denominator;
    }

    // denominator setter
    void Fraction::setDenomi(int n){
        this->denominator = n;
    }

    // implementation of the overloading of the operator << so it will print the fraction like this: 3/5
    std::ostream& operator<<(std::ostream& _os, const Fraction& fraction) {
        _os << fraction.getNumer() << '/' << fraction.getDenomi();
        return _os;
    }

    // implementation of the overloading of the + operator
    Fraction operator+(const Fraction& frac1, const Fraction& frac2){
        int numer = frac1.getNumer() * frac2.getDenomi() + frac2.getNumer() * frac1.getDenomi();
        int denomi = frac1.getDenomi() * frac2.getDenomi();
        Fraction result(numer,denomi);
        return result;
    }

    // imlementation of the overloading of the operator + for Fraction + float
    Fraction operator+(const Fraction& frac, const float& flo){
        float floFrac = static_cast<float>(frac.getNumer()) / frac.getDenomi();
        float result = floFrac + flo;
        int new_numer = round(result * frac.getDenomi());
        Fraction ans(new_numer, frac.getDenomi());
        return ans;
    }

    // imlementation of the overloading of the operator + for float + Fraction 
    Fraction operator+(const float& flo, const Fraction& frac){
        return frac + flo;
    }

    // implementation of the overloading of the - operator
    Fraction operator-(const Fraction& frac1, const Fraction& frac2){
        int numer = frac1.getNumer() * frac2.getDenomi() - frac2.getNumer() * frac1.getDenomi();
        int denomi = frac1.getDenomi() * frac2.getDenomi();
        Fraction result(numer,denomi);
        return result;
    }

    // implementation of the overloading of the - operator for Fraction - float
    Fraction operator-(const Fraction& frac, const float& flo){
        float floFrac = static_cast<float>(frac.getNumer()) / frac.getDenomi();
        float result = floFrac - flo; 
        int new_numer = round(result * frac.getDenomi());
        Fraction ans(new_numer, frac.getDenomi());
        return ans;
    }

    // implementation of the overloading of the - operator for float - Fraction
    Fraction operator-(const float& flo, const Fraction& frac){
        float floFrac = static_cast<float>(frac.getNumer()) / frac.getDenomi();
        float result = flo - floFrac; 
        int new_numer = round(result * frac.getDenomi());
        Fraction ans(new_numer, frac.getDenomi());
        return ans;
    }

    //implementation of the overloading of the / operator
    Fraction operator/(const Fraction& frac1, const Fraction& frac2){
        int numer = frac1.getNumer() * frac2.getDenomi();
        int denomi = frac1.getDenomi() * frac2.getNumer();
        Fraction result(numer,denomi);
        return result;
    }

    // implementation of the overloading of the / operator for Fraction / float
    Fraction operator/(const Fraction& frac, const float& flo){
        float floFrac = static_cast<float>(frac.getNumer()) / frac.getDenomi();
        float result = floFrac / flo; 
        int new_numer = round(result * frac.getDenomi());
        Fraction ans(new_numer, frac.getDenomi());
        return ans;
    }

    // implementation of the overloading of the / operator for float / Fraction
    Fraction operator/(const float& flo, const Fraction& frac){
        int numer = flo * frac.getDenomi();
        int denomi = frac.getNumer();
        Fraction result(numer, denomi);
        return result;
    }

    //implementation of the overloading of the * operator
    Fraction operator*(const Fraction& frac1, const Fraction& frac2){
        int numer = frac1.getNumer() * frac2.getNumer();
        int denomi = frac1.getDenomi() * frac2.getDenomi();
        Fraction result(numer,denomi);
        return result;
    }

    // implementation of the overloading of the * operator for float * fraction
    Fraction operator*(const float& flo, const Fraction& frac){
        int numer = round(flo * frac.getNumer());
        int denomi = frac.getDenomi();
        Fraction result(numer,denomi);
        return result;
    }

    // implementation of the overloading of the * operator for fraction * float
    Fraction operator*(const Fraction& frac, const float& flo){
        int numer = round(frac.getNumer() * flo);
        int denomi = frac.getDenomi();
        Fraction result(numer, denomi);
        return result;
    }

    // implementation for the prefix increment operator
    Fraction& Fraction::operator++(){
        int theNumer = this->getNumer();
        int theDenomi = this->getDenomi();
        this->setNumer(theNumer + theDenomi);
        return *this;
    }

    // implementation for the postfix increment operator
    // the postfix increment operator should return the original value
    // before it was incremented, 
    // not the new value after the increment.
    Fraction Fraction::operator++(int){
        Fraction temp(*this); 
        int theNumer = this->getNumer();
        int theDenomi = this->getDenomi();
        this->setNumer(theNumer + theDenomi);
        return temp; 
    }

    // implementation for the pre-decrement operator
    Fraction& Fraction::operator--(){
        int theNumer = this->getNumer();
        int theDenomi = this->getDenomi();
        this->setNumer(theNumer - theDenomi);
        return *this;
    }

    // implementation for the post-decrement operator
    Fraction Fraction::operator--(int){
        Fraction temp(*this); 
        int theNumer = this->getNumer();
        int theDenomi = this->getDenomi();
        this->setNumer(theNumer - theDenomi);
        return temp; 
    }

    // implementation for the >= operator
    bool Fraction::operator>=(const Fraction& frac){
        return false;
        // TODO
    }

    bool Fraction::operator>(const float& flo){
        return false;
        // TODO
    }

    bool Fraction::operator==(const Fraction& frac){
        return false;
        // TODO
    }
}