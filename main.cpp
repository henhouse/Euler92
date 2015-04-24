/* 
 * File:   main.cpp
 * Author: henryhenderson
 *
 * Created on April 23, 2015, 6:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const int TENMILL = 10000000;
const int TWO = 2;
int numOf89s = 0;

// Returns digit value at index
// Credit: http://stackoverflow.com/a/11354607
int getDigit(int from, int index)
{
   return (from / (int)pow(10, floor(log10(from)) - index)) % 10;
}

// Returns int of length of int passed
// Eg: pass the number 483 will return '3'
int numLength(int n)
{
    int digits = 0;

    do {
     ++digits; 
     n /= 10;
    } while (n);
    
    return digits;
}

// Sums the squares of each digit in a number
// Eg: 42, 4^2 + 2^2 = 20
int sqSum(int num)
{
    int sum = 0;

    for (int i = 0; i < numLength(num); i++)
        sum += pow(getDigit(num, i), TWO);

    return sum;
}

int main(int argc, char** argv)
{
    bool iterate = true;
    int sum = 0;

    for (int i = 1; i < TENMILL; i++)
    {
        sum = 0; // reset after each recurse ends
        iterate = true;

        while (iterate)
        {
            if (sum)
                sum = sqSum(sum);
            else
                sum = sqSum(i);

            switch (sum)
            {
                case 89:
                    numOf89s++;
                case 1:
                    iterate = false;
                    continue;
            }
        }
    }

    cout << numOf89s << endl;

    return 0;
}
