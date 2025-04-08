#include <iostream>
#include <fstream> //in order to input from and output to files
#include <sstream>

/* Everything in the comments starting from now is a variable of the code if it's written between < >, like < variable > */

using namespace std;

int main(){

    ifstream data("data.txt"); //opening the input file into the variable < data >

    if (data.fail()){
        cerr << "Could not open file."<< endl;
        return 1;
    }

    /* The 1st line of the file tells us how much we're investing, which we'll memorize in the variable < S > */
    char useless1; //This variable will house the simple character S
    char useless2; //This variable will house the divider ";"
    int S; //This variable will house the sum we're investing

    data >> useless1; //This is the simple character S
    data >> useless2; //This is the divider ";"
    data >> S; //This is the sum we're interested in

    /* The 2nd line of the file tells us how many assets we're investing in, which we'll memorize in the variable < n > */
    int n; //This variable will house the number of assets we're investing in

    data >> useless1;
    data >> useless2;
    data >> n;

    /* The 3rd line of the file is a header, which is useless for this assignment */
    data >> useless1;
    data >> useless1;
    data >> useless1;

    /* After the header, there are the numbers representing the fraction of S invested in each asset and 
    the rate of return of each one. I'll memorize them into 2 arrays, which will have < n > elements */
    float w[n]; // We don't need to use the "double" type, because the numbers have 2 decimal digits in file "data.txt"
    float r[n];

    short int index = 0;
    while(index < n){
        data >> w[index]; // The 1st number from the line will be part of the array < w >
        data >> useless1; // There is a divider between the two numbers we're interested in
        data >> r[index]; // The 2nd number from the line will be part of the array < r >

        index++;
    }

    cout << "Size of w: " << sizeof(w)/4 << endl;

    data.close(); //optional, not necessary: when <data> gets out of scope, the file is closed automatically
    return 0;
}

