#include <cstdint>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // Use long long so that -INT_MIN does not overflow.
        long long e = n;
        if (e < 0) {
            x = 1.0 / x;
            e = -e;
        }
        double result = 1.0;
        // Binary exponentiation: O(log n) multiplications.
        while (e > 0) {
            if (e & 1) result *= x;
            x *= x;
            e >>= 1;
        }
        return result;
    }
};
