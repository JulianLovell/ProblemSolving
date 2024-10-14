#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class CubeStickers {
public:
    string isPossible(vector<string> sticker) {
        // To store the count of each color
        unordered_map<string, int> colorCount;
        
        // Count the occurrences of each color
        for (string s : sticker) {
            colorCount[s]++;
        }

        int usableStickers = 0;
        
        // For each color, add min(count, 2) to the usable stickers count
        for (auto it : colorCount) {
            // We can use at most 2 stickers of each color
            usableStickers += min(it.second, 2);
        }

        // If we can use at least 6 stickers, return "YES", otherwise "NO"
        return (usableStickers >= 6) ? "YES" : "NO";
    }
};
