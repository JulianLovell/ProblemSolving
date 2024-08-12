#include <algorithm>
#include <string>

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

        if (r <= 0) {
            // left with green and blue
            fullCycles = min(g, b);
            if (k < 2 * fullCycles) {
                return k % 2 == 0 ? "GREEN" : "BLUE";
            }
            g -= fullCycles;
            b -= fullCycles;
            k -= 2 * fullCycles;
        } else if (g <= 0) {
            // left with red and blue
            fullCycles = min(r, b);
            if (k < 2 * fullCycles) {
                return k % 2 == 0 ? "RED" : "BLUE";
            }
            r -= fullCycles;
            b -= fullCycles;
            k -= 2 * fullCycles;
        } else if (b <= 0) {
            // left with red and green
            fullCycles = min(r, g);
            if (k < 2 * fullCycles) {
                return k % 2 == 0 ? "RED" : "GREEN";
            }
            r -= fullCycles;
            g -= fullCycles;
            k -= 2 * fullCycles;
        }
        if (r > 0) return "RED";
        if (g > 0) return "GREEN";
        return "BLUE";

        return "";  // Should not reach here
    }
};
