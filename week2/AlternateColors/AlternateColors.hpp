#include <string>
using namespace std;

class AlternateColors {
public:
    string getColor(long r, long g, long b, long k) {
        // If kth ball is red then return RED
        if (k <= r+1) {
            return "RED";
        }
        
        // If kth ball is green then return green
        if (k <= r + g+1) {
            return "GREEN";
        }
        
        // Otherwise kth ball must be blue
        return "BLUE";
    }
};