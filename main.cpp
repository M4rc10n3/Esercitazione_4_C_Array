#include <iostream> // in order to use streams on the standard and the error output
#include <fstream> // in order to input from and output to files
#include <iomanip> // in order to manipulate input and output
#include "Utils.hpp"
/* I tried to make the code work without using any string or the function "getline()"*/


/* Everything in the comments starting from now is a variable of the code if it's written between < >, like this: < variable > */

using namespace std;

int main(){

    ifstream data("data.txt"); //opening the input file into the variable < data >

    /* Printing an error if file couldn't be opened */
    if (data.fail()){
        cerr << "Could not open file."<< endl;
        return 1;
    }

    /* The 1st line of the file tells us how much we're investing, which we'll memorize in the variable < S > */
    char useless; //This variable will house the characters of the file that we don't need
    float S; //This variable will house the sum we're investing

    data >> useless; //This is the simple character S
    data >> useless; //This is the divider ";"
    data >> S; //This is the sum we're interested in

    /* The 2nd line of the file tells us how many assets we're investing in, which we'll memorize in the variable < n > */
    unsigned long long int n; //This variable will house the number of assets we're investing in, that we don't know beforehand

    data >> useless; //This is the simple character n
    data >> useless; //This is the divider ";"
    data >> n; //This is the number of assets we're interested in

    /* The 3rd line of the file is a header, which is useless for this assignment */
    data >> useless;
    data >> useless;
    data >> useless;

    /* After the header, there are the numbers representing the fractions of < S >, contained in < w >, invested in each asset and 
    the rate of return of each one of them, contained in < r >. 
    < w > and < r > are 2 arrays, each one with < n > elements */
    float w[n]; // We don't need to use the "double" type, because the numbers have just 2 decimal digits in the file "data.txt"
    float r[n];
    float V = 0; // The money total we'll have after a year of investment
    unsigned long long int index = 0ull; //We don't know how big < n > will be, so also < index > must be of the same type of < n >

    float total_percentage = 0; //Used to print an error message if the amount of money invested is not the total
    while(index < n){
        data >> w[index]; // The 1st number from the line will be part of the array < w >
        data >> useless; // There is a divider ";" between the two numbers we're interested in
        data >> r[index]; // The 2nd number from the line will be part of the array < r >

        /* Let's calculate how much our money has grown during the year because of the investments. The total of our investments 
        < S > is divided into many portions represented by the percentages contained in < w >. For each of them, we can 
        calculate how much they will grow using the formula provided in the assignment: V = (1 + r) * S. So, the formula will become 
        <partial_total> = (1 + r[index]) * w[index] * S */

        V += (1 + r[index]) * w[index] * S;

        total_percentage += w[index];
        index++;
    }

    /* Let's print an error message if the amount of money invested is not the total available */
    if(total_percentage != 1.0){
        cerr << "Be careful: your plan of investment doesn't involve all of your money. Are you sure about that? " << endl;
    }

    /* Let's print on a file called "result.txt" what is asked by the assignment */
    ofstream result("result.txt");

    /* In order to keep the "trailing zeros" I use iomanipulator "setprecision" */
    result << "S = " << fixed << setprecision(2) << S << ", ";
    result << "n = " << n << endl;

    result << "w = [ ";
    /* I implemented a function to avoid writing a 'for' cycle neede for printing the elements of the array 
    just for getting to know how to do it */
    printArray(result, w, n);
    result << "]" << endl;

    result << "r = [ ";
    printArray(result, r, n);
    result << "]" << endl;

    result << "Rate of return of the portfolio: " << setprecision(4) << (V-S)/S << endl;
    result << "V: " << setprecision(2) << V << endl;

    data.close(); //optional, not necessary: when <data> gets out of scope, the file is closed automatically
    result.close(); //same as above

    return 0;
}