#include <string>
using namespace std;

class AlternateColors {
public:
    string getColor(long r, long g, long b, long k) {
        long destroyed = 0;

        while (destroyed < k) {
            // If there is at least one red ball, destroy it
            if (r > 0) {
                r--;
                destroyed++;
                // Return if this is the Kth ball destroyed
                if (destroyed == k) return "RED";
            }

            // If there is at least one green ball, destroy it
            if (g > 0) {
                g--;
                destroyed++;
                // Return if this is the Kth ball destroyed
                if (destroyed == k) return "GREEN";
            }

            // If there is at least one blue ball, destroy it
            if (b > 0) {
                b--;
                destroyed++;
                // Return if this is the Kth ball destroyed
                if (destroyed == k) return "BLUE";
            }
        }

        return "";
    }
};