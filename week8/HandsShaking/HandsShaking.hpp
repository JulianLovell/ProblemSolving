#include <vector>

class HandsShaking {
public:
    long countPerfect(int n) {
        // Catalan number sequence for up to n/2 businessmen
        std::vector<long> catalan(n / 2 + 1, 0);
        catalan[0] = 1; // Base case: C_0 = 1

        // Fill in the Catalan numbers using DP
        for (int i = 1; i <= n / 2; ++i) {
            catalan[i] = 0;
            for (int j = 0; j < i; ++j) {
                catalan[i] += catalan[j] * catalan[i - 1 - j];
            }
        }

        return catalan[n / 2];
    }
};
