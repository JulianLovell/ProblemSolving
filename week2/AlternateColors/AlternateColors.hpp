#include <string>
using namespace std;

class AlternateColors {
public:
    string getColor(long r, long g, long b, long k) {
        // If kth ball is red then return RED
        if (k <= r) {
            return "RED";
        }
        
        // If kth ball is green then return green
        if (k <= r + g) {
            return "GREEN";
        }
        
        // Otherwise kth ball must be blue
        return "BLUE";
    }
};