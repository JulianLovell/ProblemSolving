#include <iostream>
#include <string>

using namespace std;

class ExerciseMachine {
public:
    int getPercentages(string time) {
        // Convert HH:MM:SS into total seconds, this is assuming that if it is 2 hours this will be displayed as '02:...' not '2:...'
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        int seconds = stoi(time.substr(6, 2));

        int totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
        int count = 0;

        // Check percentages from 1% to 99%
        for (int i = 1; i < 100; i++) {
            if ((totalSeconds * i) % 100 == 0) {
                count++;
            }
        }

        return count;
    }
};