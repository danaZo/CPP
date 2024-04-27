/*                   MagicalContainer.hpp
   ======================================================================
   This header file defines the MagicalContainer class, which represents 
   a container for storing integers in a magical way.

   The MagicalContainer class provides the following functionality:
   - Adding elements: The addElement() function allows adding an integer 
     element to the container.
   - Removing elements: The removeElement() function allows removing a 
     specified integer element from the container.
   - Size retrieval: The size() function returns the current size of the 
     container.

   Iterators:
   The MagicalContainer class also provides three iterator classes for 
   iterating over the elements in different ways:
   1. AscendingIterator: Iterates over the elements in ascending order.
   2. SideCrossIterator: Iterates over the elements in a side-to-side 
      cross pattern.
   3. PrimeIterator: Iterates over the prime number elements in the 
      container.

   Each iterator class supports the following operations:
   - Default constructor: Constructs an iterator object.
   - Copy constructor: Constructs an iterator object from another iterator 
     object.
   - Destructor: Destroys the iterator object.
   - Assignment operator: Assigns the value of one iterator object to 
     another.
   - Greater-than (>) and less-than (<) comparison operators: Compare the 
     iterators based on their location in the container.
   ======================================================================
*/

#pragma once

#include <vector>

using namespace std;

namespace ariel {

class MagicalContainer {
    private:
        vector<int> elements;

    public:
        MagicalContainer();
        void addElement(int element);

        void removeElement(int element);

        int size() const;

        // AscendingIterator
        class AscendingIterator {
        
        private:
            vector<int>::iterator element_ptr;

        public:
            // constructor
            AscendingIterator(MagicalContainer& container);
            // default constructor
            AscendingIterator();
            // copy constructor
            AscendingIterator(const AscendingIterator& other);
            // destructor
            ~AscendingIterator();
            // assignment operator
            AscendingIterator& operator=(const AscendingIterator& other);
            // equality comparison
            bool operator==(const AscendingIterator& other) const;
            // inequality comparison
            bool operator!=(const AscendingIterator& other) const;
            // dereference operator
            int& operator*() const;
            // GT
            bool operator>(const AscendingIterator& other) const;
            // LT
            bool operator<(const AscendingIterator& other) const;
            // pre increment
            AscendingIterator& operator++();

            AscendingIterator begin();

            AscendingIterator end();

            // to keep tidy satisfied
            AscendingIterator(AscendingIterator&&) = delete;
            AscendingIterator& operator=(AscendingIterator&&) = delete;
        };

        // SideCrossIterator
        class SideCrossIterator {
        private:

        public:
            // constructor
            SideCrossIterator(MagicalContainer& container);
            // default constructor
            SideCrossIterator();
            // copy constructor
            SideCrossIterator(const SideCrossIterator& other);
            // destructor
            ~SideCrossIterator();
            // assignment operator
            SideCrossIterator& operator=(const SideCrossIterator& other);
            // equality comparison
            bool operator==(const SideCrossIterator& other) const;
            // inequality comparison
            bool operator!=(const SideCrossIterator& other) const;
            // dereference operator
            int& operator*() const;
            // GT
            bool operator>(const SideCrossIterator& other) const;
            // LT
            bool operator<(const SideCrossIterator& other) const;
            // pre increment
            SideCrossIterator& operator++();

            SideCrossIterator begin();

            SideCrossIterator end();

            // to keep tidy satisfied
            SideCrossIterator(SideCrossIterator&&) = delete;
            SideCrossIterator& operator=(SideCrossIterator&&) = delete;
        };

        // PrimeIterator
        class PrimeIterator {
        private:

        public: 
            // constructor
            PrimeIterator(MagicalContainer& container);
            // default constructor
            PrimeIterator();
            // copy constructor
            PrimeIterator(const PrimeIterator& other);
            // destructor
            ~PrimeIterator();
            // assignment operator
            PrimeIterator& operator=(const PrimeIterator& other);
            // equality comparison
            bool operator==(const PrimeIterator& other) const ;
             // inequality comparison
            bool operator!=(const PrimeIterator& other) const;
            // dereference operator
            int& operator*() const;
            // GT
            bool operator>(const PrimeIterator& other) const;
            // LT
            bool operator<(const PrimeIterator& other) const;
            // pre increment
            PrimeIterator& operator++();

            PrimeIterator begin();

            PrimeIterator end();

            // to keep tidy satisfied
            PrimeIterator(PrimeIterator&&) = delete;
            PrimeIterator& operator=(PrimeIterator&&) = delete;

        };

    };

} 
