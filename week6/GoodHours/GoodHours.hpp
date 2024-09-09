#include <iostream>
#include <string>

using namespace std;

class GoodHours {
public:
    int howMany(string beforeTime, string afterTime) {
        // Initialise count
        int count = 0;

        // First, convert time from the given HH:MM format to total minutes since midnight
        auto timeToMinutes = [](const string& time) {
            // Hours conversion
            int hours = stoi(time.substr(0, 2));
            // Minutes conversion
            int minutes = stoi(time.substr(3, 2));
            return hours * 60 + minutes;
        };

        // Get total minutes for beforeTime and afterTime
        int startTime = timeToMinutes(beforeTime);
        int endTime = timeToMinutes(afterTime);

        // Handle the case where afterTime is earlier in the day by adding 24 hours
        if (endTime < startTime) {
            // I know brackets aren't needed here but i like to do my math using them to make it easier to read what's happening
            endTime += (24 * 60);
        }

        // Loop over each minute between startTime and endTime
        for (int t = startTime; t <= endTime; ++t) {
            // Convert current time (in minutes) back to hours and minutes
            // Hours
            int h = (t / 60) % 24;
            // Minutes
            int m = t % 60;

            // Get digits for HH:MM
            // Hours digits
            int h1 = h / 10, h2 = h % 10;
            //Minutes digits
            int m1 = m / 10, m2 = m % 10;

            // Check the three possible splits for "good time"
            if ((h1 * h2 == m1 * m2) || (h1 == h2 * m1 * m2) || (h1 * h2 * m1 == m2)) {
                count++;
            }
        }

        // Return the final count
        return count;
    }
};