#include "MagicalContainer.hpp"

namespace ariel {

    MagicalContainer::MagicalContainer(){}

    void MagicalContainer::addElement(int element) {
        //TODO
    }

    void MagicalContainer::removeElement(int element) {
       //TODO
    }

    int MagicalContainer::size() const {
        return elements.size();
    }

    // AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) {
        //TODO
        element_ptr = container.elements.begin();
    }

    // default constructor
    MagicalContainer::AscendingIterator::AscendingIterator(){

    }

    // copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other){

    }

    // destructor
    MagicalContainer::AscendingIterator::~AscendingIterator(){

    }

    // assignment operator
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
        // TODO
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        //TODO
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        //TODO
        return false;
    }

    int& MagicalContainer::AscendingIterator::operator*() const {
        //TODO
        int* element_ptr = nullptr; 
        return *element_ptr;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        //TODO
        return *this;
    }

    // GT
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
        //TODO
        return false;
    }

    // LT
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
        //TODO
        return false;
    }


    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        //TODO
        return AscendingIterator(*this);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        //TODO
        return AscendingIterator(*this);
    }





    // SideCrossIterator
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) {
        //TODO
    }

    // default constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(){

    }

    // copy constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other){

    }

    // destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){

    }

    // assignment operator
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
        // TODO
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        //TODO
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        //TODO
        return false;
    }

    int& MagicalContainer::SideCrossIterator::operator*() const {
        //TODO
        int* element_ptr = nullptr; 
        return *element_ptr;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        //TODO
        return *this;
    }

    // GT
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
        //TODO
        return false;
    }
    
    // LT
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
        //TODO
        return false;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        //TODO
        return SideCrossIterator(*this);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        //TODO
        return SideCrossIterator(*this);
    }







    // PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) {
        //TODO
    }

    // default constructor
    MagicalContainer::PrimeIterator::PrimeIterator(){

    }
    
    // copy constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other){

    }
    
    // destructor
    MagicalContainer::PrimeIterator::~PrimeIterator(){

    }
    
    // assignment operator
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){
        // TODO
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        //TODO
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        //TODO
        return false;
    }

    int& MagicalContainer::PrimeIterator::operator*() const {
        //TODO
        int* element_ptr = nullptr;
        return *element_ptr;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        //TODO
        return *this;
    }

    // GT
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{
        //TODO
        return false;
    }
            
    // LT
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{
        //TODO
        return false;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        //TODO
        return PrimeIterator(*this);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        // TODO
        return PrimeIterator(*this);
    }
}
