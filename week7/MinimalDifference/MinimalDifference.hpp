#include <iostream>

using namespace std;

class MinimalDifference {
    public:
    int findNumber(int A, int B, int C){
        int closest = A;

        // find digit sum of C
        int num = C;
        int goalDigitSum = 0;
        int mod = 0;

        while (num > 0){
            mod = num % 10;
            goalDigitSum = goalDigitSum + mod;
            num = num/10;
        }

        // Iterate through elements A -> B, checking for closest digit sum
        for (int i = A; i <= B; ++i){
            // find digit sum of i
            int num = i;
            int currentDigitSum = 0;
            int mod = 0;

            // digit sum calc
            while(num > 0){    
            mod = num % 10;    
            currentDigitSum = currentDigitSum + mod;    
            num = num/10;    
            }

            // if currentDigitSum == c, return current number
            if (currentDigitSum == goalDigitSum){
                return i;

            // else if c - currentDigitSum < c - closest, then closest = current number
            } else if ((C - currentDigitSum) < (C - goalDigitSum)){
                closest = i;
            }
            


        }
        return closest;
    }
};
