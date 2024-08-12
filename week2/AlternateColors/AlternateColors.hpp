#include <string>
#include <algorithm>

using namespace std;

class AlternateColors {
public:
    string getColor(long r, long g, long b, long k) {
        k -= 1;
        // Find the number of full cycles we can skip
        long fullCycles = min(r, min(g, b));
        if (k < 3 * fullCycles) {
            k = k % 3;
            if (k == 0) k = 3;
            if (k == 1) return "RED";
            if (k == 2) return "GREEN";
            return "BLUE";
        }

        // Reduce k by the number of full cycles skipped
        k -= 3 * fullCycles;
        r -= fullCycles;
        g -= fullCycles;
        b -= fullCycles;

        // Handle remaining destructions in loop
        while (k > 0) {
            if (r > 0) {
                r--;
                k--;
                if (k == 0) return "RED";
            }
            if (g > 0) {
                g--;
                k--;
                if (k == 0) return "GREEN";
            }
            if (b > 0) {
                b--;
                k--;
                if (k == 0) return "BLUE";
            }
        }

        return "";  // Should not reach here
    }
};
