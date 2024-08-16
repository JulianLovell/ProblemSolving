#include <iostream>
#include <string>
#include <climits>

using namespace std;

class QuickSums {
public:
    int minSums(string numbers, int sum) {
        return minSumsHelper(numbers, sum, 0, 0, 0);
    }

    int minSumsHelper(const string& numbers, int target, int pos, int currentSum, int additions) {
        if (pos == numbers.length()) {
            return (currentSum == target) ? additions : INT_MAX;
        }

        int result = INT_MAX;
        int num = 0;

        for (int i = pos; i < numbers.length(); ++i) {
            num = num * 10 + (numbers[i] - '0');
            result = min(result, minSumsHelper(numbers, target, i + 1, currentSum + num, additions + (pos != 0)));
        }

        return result;
    }
};