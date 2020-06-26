#pragma once
// functions to manipulate variable size array
// Antonio S.-M.
// 3/29/2020

#ifndef VARARRAY_HPP
#define VARARRAY_HPP

// prints the values in "arrayPtr" of "size" 
void output(double* arrayPtr, int size);

// returns the index of the element in "arrayPtr" of "size"
// that corresponds to the element holding "number"
// if number is not in the array, returns -1
int check(double* arrayPtr, double number, int size);

// adds "number" to the array pointed to by "arrayPtr" of "size". 
// if the number is not already there, if "number" is there - no action
// Note, the size of the array is thus increased. 
void addNumber(double*& arrayPtr, double number, int& size);

// removes a "number" from the "arrayPtr" of "size".
// if "number" is not there -- no action
// note, "size" changes
void removeNumber(double*& arrayPtr, double number, int& size);

#endif // VARARRAY_HPP