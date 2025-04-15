#pragma once

using namespace std;

/* printArray prints the content of an array into an output file 
   output: stream containing the output file
   array: the array to print 
   n: array dimension*/
int printArray(ofstream& output,
   const float* const& array,
   const unsigned long long int& n);
