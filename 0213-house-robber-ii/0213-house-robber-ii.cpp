#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // This is your exact House Robber 1 logic, just bundled into a helper function!
    int robLinear(vector<int>& nums, int start, int end) {
        int prev = 0;
        int prev2 = 0;
        
        for(int i = start; i <= end; i++) {
            int take = nums[i] + prev2;
            int notake = prev;
            
            int curr = max(take, notake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases
        if (n == 0) return 0;
        if (n == 1) return nums[0]; // If there is only 1 house, just rob it!
        
        // Scenario 1: Rob from index 0 to n-2 (Skip the last house)
        int ans1 = robLinear(nums, 0, n - 2);
        
        // Scenario 2: Rob from index 1 to n-1 (Skip the first house)
        int ans2 = robLinear(nums, 1, n - 1);
        
        // Return the absolute maximum of both scenarios
        return max(ans1, ans2);
    }
};