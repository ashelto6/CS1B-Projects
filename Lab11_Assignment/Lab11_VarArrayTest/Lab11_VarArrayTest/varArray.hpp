#pragma once
// variable size array class
// Antonio S.-M.
// 4/14/2020


#ifndef VARARRAY_HPP_
#define VARARRAY_HPP_

class varArray {
public:
    varArray() : array_(new double[size_]), size_(0) {} // void constructor
    int arraySize() const { return size_; } // returns the size of the array

    int check(double number); // returns index of element containg "number" or -1 if none
    void addNumber(double number);    // adds number to the array
    void removeNumber(double number); // deletes the number from the array
    void output();      // prints the values of the array

    //big three
    varArray(const varArray&); // copy constructor
    varArray& operator=(const varArray&); // overloaded assignment
    ~varArray() { delete[] array_; } // destructor

private:
    double* array_; // pointer to the dynamically allocated array
    int size_;   // array size
};

#endif /* VARARRAY_HPP_ */
