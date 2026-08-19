#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_indices;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (num_indices.find(complement) != num_indices.end()) {
                return {num_indices[complement], i};
            }
            num_indices[nums[i]] = i;
        }
        return {};
    }
};