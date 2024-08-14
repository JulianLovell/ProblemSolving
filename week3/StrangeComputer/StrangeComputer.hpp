#include <iostream>
#include <string>

using namespace std;

class StrangeComputer {
public:
    int setMemory(string mem) {
        int operations = 0;
        // Start initial memory being all 0's
        char currentBit = '0';

        // Iterate through each bit in the target memory `mem`
        for (int i = 0; i < mem.length(); i++) {
            if (mem[i] != currentBit) {
                // We need to perform an operation to change the memory
                operations++;
                // Update current bit to new value
                currentBit = mem[i];
            }
        }

        return operations;
    }
};