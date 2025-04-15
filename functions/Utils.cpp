#include <fstream>
#include <iostream>

using namespace std;

int printArray(ofstream& output,
    const float* const& array,
    const unsigned long long int& n){

    for(int j = 0; j < n; j++){
        output << array[j] << " ";
    }

    return 0;
}
