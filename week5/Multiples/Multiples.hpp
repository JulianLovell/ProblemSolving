#include <iostream>

using namespace std;

class Multiples{
    public:

    int number(int min, int max, int factor){
        // Initialise counter
        int counter = 0;

        // For loop to iterate through each element in range
        for (int i = min; i <= max; ++i){
            // Check if element is divisible by 'factor'
            if (i % factor == 0){
                counter ++;
            }
        }
        // Return the counter
        return counter;
    }
};