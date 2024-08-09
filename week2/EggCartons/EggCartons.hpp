class EggCartons {
public:
    int minCartons(int n) {
        // Immediate return for odd numbers
        if (n % 2 != 0) {
            return -1;
        }

        // Try to maximize the number of 8-egg cartons, iterating through and adding in the smaller cartons gradually
        for (int num8Cartons = n / 8; num8Cartons >= 0; num8Cartons--) {
            int remainingEggs = n - num8Cartons * 8;
            if (remainingEggs % 6 == 0) {
                int num6Cartons = remainingEggs / 6;
                return num8Cartons + num6Cartons;
            }
        }

        // Finally if no combination is found
        return -1;
    }
};
