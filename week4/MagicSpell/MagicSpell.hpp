#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MagicSpell {
public:
    string fixTheSpell(string spell) {
        vector<char> azTemp;

        // Collect all A and Z characters in their original order
        for (char c : spell) {
            if (c == 'A' || c == 'Z') {
                azTemp.push_back(c);
            }
        }

        // Reverse the A and Z characters in temp
        reverse(azTemp.begin(), azTemp.end());

        // Place back into spell to create corrected spell
        int azIndex = 0;
        for (int i = 0; i < spell.length(); i++) {
            if (spell[i] == 'A' || spell[i] == 'Z') {
                spell[i] = azTemp[azIndex++];
            }
        }

        return spell;
    }
};