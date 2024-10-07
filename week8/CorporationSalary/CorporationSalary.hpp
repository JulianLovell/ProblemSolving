#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CorporationSalary {
public:
    // Method to calculate the total salary
    long totalSalary(vector<string> relations);

private:
    // Helper function to compute individual salaries
    long computeSalary(int emp, vector<vector<int>> &subordinates, vector<long> &memo);
};

// Implementation of the helper function
long CorporationSalary::computeSalary(int emp, vector<vector<int>> &subordinates, vector<long> &memo) {
    // Return memoized salary if already computed
    if (memo[emp] != -1) {
        return memo[emp];
    }

    // If no subordinates, salary is 1
    if (subordinates[emp].empty()) {
        memo[emp] = 1;
        return 1;
    }

    // Sum salaries of all direct subordinates
    long salary = 0;
    for (int sub : subordinates[emp]) {
        salary += computeSalary(sub, subordinates, memo);
    }

    // Memoize and return the computed salary
    memo[emp] = salary;
    return salary;
}

// Implementation of the totalSalary method
long CorporationSalary::totalSalary(vector<string> relations) {
    int N = relations.size();

    // Build subordinates list for each employee
    vector<vector<int>> subordinates(N, vector<int>());
    for (int manager = 0; manager < N; manager++) {
        for (int subordinate = 0; subordinate < N; subordinate++) {
            if (relations[manager][subordinate] == 'Y') {
                subordinates[manager].push_back(subordinate);
            }
        }
    }

    // Initialize memoization array with -1
    vector<long> memo(N, -1);

    // Calculate total salary by summing salaries of all employees
    long total = 0;
    for (int emp = 0; emp < N; emp++) {
        total += computeSalary(emp, subordinates, memo);
    }

    return total;
}