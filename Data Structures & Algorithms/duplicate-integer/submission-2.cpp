
#include <vector>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return false;  // If there are less than 2 elements, there can't be duplicates
        }

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j]) {
                    return true;  // Duplicate found
                }
            }
        }

        return false;  // No duplicates found
    }
};


