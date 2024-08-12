#include <string>
using namespace std;

class AlternateColors {
public:
    string getColor(long r, long g, long b, long k) {
        // Loop through destorying in the order of Red, Green, Blue, skipping if none and then stopping and returning final destroyed ball if Kth destruction
        while (k > 0) {
            // Red ball destruction
            if (r > 0) {
                r--;
                k--;
                if (k == 0) return "RED";
            }

            // Green ball destruction
            if (g > 0) {
                g--;
                k--;
                if (k == 0) return "GREEN";
            }

            // Blue ball destruction
            if (b > 0) {
                b--;
                k--;
                if (k == 0) return "BLUE";
            }
            
            // If all balls are destroyed and k hasn't reached 0
            if (r == 0 && g == 0 && b == 0) {
                break;
            }
        }

        return "";
    }
};