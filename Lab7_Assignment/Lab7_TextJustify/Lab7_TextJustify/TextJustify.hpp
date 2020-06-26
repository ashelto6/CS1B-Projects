#pragma once
#ifndef TEXTJUSTIFY_HPP
#define TEXTJUSTIFY_HPP

#include <string>
using std::string;

void puncSpace(string&); // checks for punctuation, adds appropriate spacing to string
void wordSpace(string&); // adds space between random words to make the line 75 characters long 
#endif