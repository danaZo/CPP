#include "MagicalContainer.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <cmath>

/* Web sources:
    https://www.techiedelight.com/check-vector-contains-given-element-cpp/
    https://java2blog.com/remove-element-by-value-vector-cpp/
*/

namespace ariel {

    MagicalContainer::MagicalContainer(){}


    /*                    updateAscendingElements
    ======================================================================
    updating the vector the holds pointers to the elements in the main 
    vector in ascending order.

    */
    void MagicalContainer::updateAscendingElements() {
        this->ascending_elements.clear();
        this->ascending_elements.reserve(elements.size());

        for (int& element : elements) {
            this->ascending_elements.push_back(&element);
        }

        sort(this->ascending_elements.begin(), this->ascending_elements.end(), [](int* a, int* b) {
            return *a < *b;
        });
    }

    /*                   updateSideCrossElements
    ======================================================================
    updating the vector the holds pointers to the elements in the main 
    vector in cross side order.

    */
    void MagicalContainer::updateSideCrossElements() {
        this->sidecross_elements.clear();
        this->sidecross_elements.reserve(elements.size());
        vector<int*> tmp_sidecross_elements = this->ascending_elements;

        while (!tmp_sidecross_elements.empty()) {
            this->sidecross_elements.push_back(tmp_sidecross_elements.front());  // Append the first element
            tmp_sidecross_elements.erase(tmp_sidecross_elements.begin());
            if (!tmp_sidecross_elements.empty()) {
                this->sidecross_elements.push_back(tmp_sidecross_elements.back());  // Append the last element
                tmp_sidecross_elements.pop_back();
            }
        }  
    }



    /*                   updatePrimeElements
    ======================================================================
    updating the vector the holds pointers to the elements in the main 
    vector which are prime, in ascending order.

    */
    void MagicalContainer::updatePrimeElements() {
        this->prime_elements.clear();
        this->prime_elements.reserve(elements.size());

        for (int* elementPtr : ascending_elements) {
            int element = *elementPtr;
            bool isPrime = true;

            // Check if the element is prime
            if (element < 2)
                isPrime = false;
            else {
                int sqrtElement = sqrt(element);
                for (int i = 2; i <= sqrtElement; i++) {
                    if (element % i == 0) {
                        isPrime = false;
                        break;
                    }
                }
            }

            if (isPrime)
                this->prime_elements.push_back(elementPtr);
        }
    }

    void MagicalContainer::addElement(int element) {
        this->elements.push_back(element);
        this->updateAscendingElements();
        this->updateSideCrossElements();
        this->updatePrimeElements();
    }

    /*                    removeElement
    ======================================================================
    Using the std::find() function to remove element by value in vector
    1. we search the position of element in the vector elements
    2. check if the element exists in our conatiner
    3. if does - remove it using the erase method

    "The method vector::erase() is a method that helps us remove a single 
    element or a range of elements from a vector in C++ STL. 
    It destroys the deleted element and simultaneously decreases the size of 
    the container by the number of elements removed." 
    "position: The position parameter is an iterator pointing to the single 
    element that needs to get removed from the vector."
    - https://www.scaler.com/topics/which-method-is-used-to-remove-all-the-elements-from-vector/ -

    the position in our case is iter that we found using find()

    NOTE:
    If there are duplicates, it will remove only the first occurrence of 
    the element. 

    "auto keyword: The auto keyword specifies that the type of the variable 
    that is being declared will be automatically deducted from its 
    initializer. Good use of auto is to avoid long initializations when creating 
    iterators for containers. 

    Note: The variable declared with auto keyword should be initialized at the 
    time of its declaration only or else there will be a compile-time error. "

    - https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/ -

    */

    void MagicalContainer::removeElement(int element) {
        
        auto iter = find(elements.begin(), elements.end(), element);

        if (iter == elements.end()) {
            throw std::runtime_error("Element to remove is not exists in the container");
        }

        elements.erase(iter);
        this->updateAscendingElements();
        this->updateSideCrossElements();
        this->updatePrimeElements();
    }

    /*                          removeElement
    ======================================================================
    */

    int MagicalContainer::size() const {
        return elements.size();
    }









    /*                          
    ======================================================================
                            AscendingIterator
    ======================================================================
    */


    /*                    
    ======================================================================
                                constructor
    ======================================================================
    store a reference to the container in container_ptr.
    index - to keep track of the current position within the container.
    when creating an AscendingIterator object, it will store a reference to 
    the container and initialize the index to 0. The iterator does not hold 
    any additional memory or duplicate the information from the container.

    time complexity:
    Initialization of the index member variable: O(1)
    Therefore, the time complexity is O(1)
    */

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : container_ptr(container) {
        this->index = 0;
    }

    
    // copy constructor
    // time complexity:
    // Copying the container_ptr and index member variables: O(1)
    // Therefore, the time complexity is O(1).
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other): container_ptr(other.container_ptr),index(other.index){}

    /* destructor
       I don't have any additional resources or dynamically allocated memory to deallocate in the AscendingIterator class, 
       so I don't need to explicitly implement a destructor. 
       The compiler will automatically generate a default destructor, which will handle the cleanup of any resources owned by the class.
    */
    MagicalContainer::AscendingIterator::~AscendingIterator(){

    }

    // assignment operator
    // time complexity:
    // Checking if the container_ptr of both iterators is the same: O(1)
    // Assigning the container_ptr and index member variables: O(1)
    // Therefore, the time complexity is O(1).
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
        if (&this->container_ptr != &other.container_ptr) {
            throw std::runtime_error("error at : AscendingIterator::operator= , The error: not the same container.");
        }
        this->container_ptr = other.container_ptr;
        this->index = other.index;
        return *this;
    }


    /*
    ======================================================================
                                 operator ==
    ======================================================================                   
    compare both the container_ptr and index of the current iterator 
    with the members of the other iterator. 
    If both the container pointer and the index are equal, we return true, 
    means that the iterators are pointing to the same element in the 
    container. Otherwise, we return false, means that the iterators are 
    different.

    time complexity:
    - Comparing the container_ptr and index member variables of both iterators: O(1)
    Therefore, the time complexity is O(1).
    */
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        
        return (&this->container_ptr == &other.container_ptr) && (this->index == other.index);
    }

    /*
    ======================================================================
                                 operator !=
    ======================================================================                   
    using the implementation of == 

    time complexity:
    - Using the implementation of Operator==: O(1)
    Therefore, the time complexity is O(1).
    */
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }



    /*
    ======================================================================
                                 operator *
    ======================================================================

    time complexity:
    - Checking if the index is within the valid range: O(1)
    - Dereferencing the corresponding element pointer: O(1)
    Therefore, the time complexity is O(1).
    */

    int& MagicalContainer::AscendingIterator::operator*() const {
        if (this->index >= this->container_ptr.elements.size()) {
            throw std::out_of_range("error at : AscendingIterator::operator* , The error: Iterator is out of range.");
        }
        return *(this->container_ptr.ascending_elements[index]);
        
    }


    /*
    ======================================================================
                                 operator ++
    ======================================================================

    time complexity:
    - Checking if the index is within the valid range: O(1)
    - Incrementing the index member variable: O(1)
    Therefore, the time complexity is O(1).
    */

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        if (index >= container_ptr.elements.size()) {
            throw runtime_error("error at: AscendingIterator::operator++, The error: Attempt to increment beyond the end.");
        }
        this->index = ++index;
        return *this;
    }

   

    /*
    ======================================================================
                                 operator >
    ======================================================================
    using the vector of pointers to ascending order numbers in the container

    time complexity:
    -Checking if the container_ptr of both iterators is the same: O(1)
    -Accessing the elements from the ascending_elements vector using the indexes: O(1)
    Therefore, the time complexity is O(1).  
    */
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
        if (&this->container_ptr != &other.container_ptr) {
            throw std::runtime_error("error at : AscendingIterator::operator> , The error: not the same container.");
        }

        // Check if the indexes are valid
        if (this->index >= this->container_ptr.ascending_elements.size() || other.index >= other.container_ptr.ascending_elements.size()) {
            return this->index > other.index;
        }
        
        int* element1 = this->container_ptr.ascending_elements[index];
        int* element2 = other.container_ptr.ascending_elements[other.index];

        // Compare the elements
        return (*element1) > (*element2);
    }

    /*
    ======================================================================
                                 operator <
    ======================================================================
    using the implementations of operators > and !=
    if not *this > other and *this != other then true

    time complexity:
    -Using the implementations of Operator> and Operator!=: O(1)
    Therefore, the time complexity is O(1).
    */
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
        if (&this->container_ptr != &other.container_ptr) {
            throw std::runtime_error("error at : AscendingIterator::operator< , The error: not the same container.");
        }
        
        return !(*this > other) && (*this != other);
    }

    /* time complexity:
        -Creating a new AscendingIterator object: O(1)
        -Initializing the index member variable: O(1)
        Therefore, the time complexity is O(1).
    */
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        MagicalContainer::AscendingIterator iter(this->container_ptr);
        iter.index = 0;
        return iter;
    }

     /* time complexity:
        - Creating a new AscendingIterator object: O(1)
        - Setting the index member variable to the size of the ascending_elements vector: O(1)
        - Therefore, the time complexity is O(1).
    */
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        MagicalContainer::AscendingIterator iter(this->container_ptr);
        iter.index=this->container_ptr.ascending_elements.size();
        return iter;

    }









    /*                          
    ======================================================================
                            SideCrossIterator
    ======================================================================
    */







    /*                    
    ======================================================================
                                constructor
    ======================================================================
    store a reference to the container in container_ptr.
    index - to keep track of the current position within the container.
    when creating an SideCrossIterator object, it will store a reference to 
    the container and initialize the index to 0. The iterator does not hold 
    any additional memory or duplicate the information from the container.

    time complexity:
    Initialization of the index member variable: O(1)
    Therefore, the time complexity is O(1)
    */
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : container_ptr(container){
        this->index = 0;
    }

    

    // copy constructor
    // time complexity:
    // Copying the container_ptr and index member variables: O(1)
    // Therefore, the time complexity is O(1).
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other): container_ptr(other.container_ptr),index(other.index){}

    /* destructor
       I don't have any additional resources or dynamically allocated memory to deallocate in the SideCrossIterator class, 
       so I don't need to explicitly implement a destructor. 
       The compiler will automatically generate a default destructor, which will handle the cleanup of any resources owned by the class.
    */
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){

    }

    // assignment operator
    // time complexity:
    // Checking if the container_ptr of both iterators is the same: O(1)
    // Assigning the container_ptr and index member variables: O(1)
    // Therefore, the time complexity is O(1).
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
        if (&this->container_ptr != &other.container_ptr) {
            throw std::runtime_error("error at : SideCrossIterator::operator= , The error: not the same container.");
        }
        this->container_ptr = other.container_ptr;
        this->index = other.index;
        return *this;
    }



    /*
    ======================================================================
                                 operator ==
    ======================================================================                   
    compare both the container_ptr and index of the current iterator 
    with the members of the other iterator. 
    If both the container pointer and the index are equal, we return true, 
    means that the iterators are pointing to the same element in the 
    container. Otherwise, we return false, means that the iterators are 
    different.

    time complexity:
    - Comparing the container_ptr and index member variables of both iterators: O(1)
    Therefore, the time complexity is O(1).
    */
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return (&this->container_ptr == &other.container_ptr) && (this->index == other.index);
    }


    /*
    ======================================================================
                                 operator !=
    ======================================================================                   
    using the implementation of == 

    time complexity:
    - Using the implementation of Operator==: O(1)
    Therefore, the time complexity is O(1).
    */
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }



    /*
    ======================================================================
                                 operator *
    ======================================================================

    time complexity:
    - Checking if the index is within the valid range: O(1)
    - Dereferencing the corresponding element pointer: O(1)
    Therefore, the time complexity is O(1).

    */
    int& MagicalContainer::SideCrossIterator::operator*() const {
        if (this->index >= this->container_ptr.elements.size()) {
            throw std::out_of_range("Iterator is out of range.");
        }
        return *(this->container_ptr.sidecross_elements[index]);
    }



    /*
    ======================================================================
                                 operator ++
    ======================================================================

    time complexity:
    - Checking if the index is within the valid range: O(1)
    - Incrementing the index member variable: O(1)
    Therefore, the time complexity is O(1).
    */
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if (index >= container_ptr.elements.size()) {
            throw runtime_error("error at: SideCrossIterator::operator++, The error: Attempt to increment beyond the end.");
        }
        this->index = ++index;
        return *this;
    }

    /*
    ======================================================================
                                 operator >
    ======================================================================
    using the vector of pointers to side cross order numbers in the container 

    time complexity:
    -Checking if the container_ptr of both iterators is the same: O(1)
    -Accessing the elements from the sidecross_elements vector using the indexes: O(1)
    Therefore, the time complexity is O(1).  
    */
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
        if (&this->container_ptr != &other.container_ptr) {
            throw std::runtime_error("error at : AscendingIterator::operator> , The error: not the same container.");
        }

        int* element1 = this->container_ptr.sidecross_elements[index];
        int* element2 = other.container_ptr.sidecross_elements[other.index];

        // Compare the elements
        return (*element1) > (*element2);
    }
    
    /*
    ======================================================================
                                 operator <
    ======================================================================
    using the implementations of operators > and !=
    if not *this > other and *this != other then true

    time complexity:
    -Using the implementations of Operator> and Operator!=: O(1)
    Therefore, the time complexity is O(1).
    */
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
        return !(*this > other) && (*this != other);
    }


    /* time complexity:
        -Creating a new SideCrossIterator object: O(1)
        -Initializing the index member variable: O(1)
        Therefore, the time complexity is O(1).
    */
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        MagicalContainer::SideCrossIterator iter(this->container_ptr);
        iter.index = 0;
        return iter;
    }

    /* time complexity:
        - Creating a new SideCrossIterator object: O(1)
        - Setting the index member variable to the size of the sidecross_elements vector: O(1)
        - Therefore, the time complexity is O(1).
    */
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        MagicalContainer::SideCrossIterator iter(this->container_ptr);
        iter.index=this->container_ptr.sidecross_elements.size();
        return iter;
    }








    /*                          
    ======================================================================
                            PrimeIterator
    ======================================================================
    */






     /*                    
    ======================================================================
                                constructor
    ======================================================================
    store a reference to the container in container_ptr.
    index - to keep track of the current position within the container.
    when creating an PrimeIterator object, it will store a reference to 
    the container and initialize the index to 0. The iterator does not hold 
    any additional memory or duplicate the information from the container.

    time complexity:
    Initialization of the index member variable: O(1)
    Therefore, the time complexity is O(1).
    */
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : container_ptr(container){
        this->index = 0;
    }
    
    // copy constructor
    // time complexity:
    // Copying the container_ptr and index member variables: O(1)
    // Therefore, the time complexity is O(1).
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other): container_ptr(other.container_ptr),index(other.index){}
    
    /* destructor
       I don't have any additional resources or dynamically allocated memory to deallocate in the PrimeIterator class, 
       so I don't need to explicitly implement a destructor. 
       The compiler will automatically generate a default destructor, which will handle the cleanup of any resources owned by the class.
    */
    MagicalContainer::PrimeIterator::~PrimeIterator(){}
    
    // assignment operator
    // time complexity:
    // Checking if the container_ptr of both iterators is the same: O(1)
    // Assigning the container_ptr and index member variables: O(1)
    // Therefore, the time complexity is O(1).
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){
        if (&this->container_ptr != &other.container_ptr) {
            throw std::runtime_error("error at : PrimeIterator::operator= , The error: not the same container.");
        }
        this->container_ptr = other.container_ptr;
        this->index = other.index;
        return *this;
    }




    /*
    ======================================================================
                                 operator ==
    ======================================================================                   
    compare both the container_ptr and index of the current iterator 
    with the members of the other iterator. 
    If both the container pointer and the index are equal, we return true, 
    means that the iterators are pointing to the same element in the 
    container. Otherwise, we return false, means that the iterators are 
    different.

    time complexity:
    - Comparing the container_ptr and index member variables of both iterators: O(1)
    Therefore, the time complexity is O(1).
    */
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return (&this->container_ptr == &other.container_ptr) && (this->index == other.index);
    }



    /*
    ======================================================================
                                 operator !=
    ======================================================================                   
    using the implementation of == 

    time complexity:
    - Using the implementation of Operator==: O(1)
    Therefore, the time complexity is O(1).
    */
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return !(*this == other);
    }



    /*
    ======================================================================
                                 operator *
    ======================================================================
    time complexity:
    - Checking if the index is within the valid range: O(1)
    - Dereferencing the corresponding element pointer: O(1)
    Therefore, the time complexity is O(1).
    */
    int& MagicalContainer::PrimeIterator::operator*() const {
        if (this->index >= this->container_ptr.elements.size()) {
            throw std::out_of_range("Iterator is out of range.");
        }
        return *(this->container_ptr.prime_elements[index]);
    }



    /*
    ======================================================================
                                 operator ++
    ======================================================================
    time complexity:
    - Checking if the index is within the valid range: O(1)
    - Incrementing the index member variable: O(1)
    Therefore, the time complexity is O(1).
    */
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        if (this->index >= this->container_ptr.prime_elements.size()) {
            throw runtime_error("error at: PrimeIterator::operator++, The error: Attempt to increment beyond the end.");
        }
        this->index = ++index;
        return *this;
    }

    /*
    ======================================================================
                                 operator >
    ======================================================================
    using the vector of pointers to prime numbers in the container

    time complexity:
    - Checking if the container_ptr of both iterators is the same: O(1)
    - Accessing the elements from the prime_elements vector using the indexes: O(1)
    Therefore, the time complexity is O(1).   
    */
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{
        if (&this->container_ptr != &other.container_ptr) {
            throw std::runtime_error("error at : AscendingIterator::operator> , The error: not the same container.");
        }

        // Check if the indexes are valid
        if (this->index >= this->container_ptr.prime_elements.size() || other.index >= other.container_ptr.prime_elements.size()) {
            return this->index > other.index;
        }

        int* element1 = container_ptr.prime_elements[index];
        int* element2 = other.container_ptr.prime_elements[other.index];

        // Compare the elements
        return (*element1 > *element2);
        
    }
            
    /*
    ======================================================================
                                 operator <
    ======================================================================
    using the implementations of operators > and !=
    if not *this > other and *this != other then true

    time complexity:
    - Using the implementations of Operator> and Operator!=: O(1)
    Therefore, the time complexity is O(1).
    */
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{
        return !(*this > other) && (*this != other);
    }

     /* time complexity:
        - Creating a new PrimeIterator object: O(1)
        - Initializing the index member variable: O(1)
        Therefore, the time complexity is O(1).
    */
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        MagicalContainer::PrimeIterator iter(this->container_ptr);
        iter.index = 0;
        return iter;
    }

    /* time complexity:
        - Creating a new PrimeIterator object: O(1)
        - Setting the index member variable to the size of the prime_elements vector: O(1)
        Therefore, the time complexity is O(1).
    */
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        MagicalContainer::PrimeIterator iter(this->container_ptr);
        iter.index=this->container_ptr.prime_elements.size();
        return iter;
    }
}
