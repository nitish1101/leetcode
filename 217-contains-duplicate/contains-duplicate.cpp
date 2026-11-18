#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int value : nums) {
            // Insertion fails exactly when this value was seen before.
            if (!seen.insert(value).second) return true;
        }
        return false;
    }
};
