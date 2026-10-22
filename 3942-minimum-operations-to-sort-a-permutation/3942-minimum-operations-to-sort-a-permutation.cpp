class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                pos = i;
                break;
            }
        }
        
        bool is_asc = true;
        for (int i = 0; i < n; i++) {
            if (nums[(i + 1) % n] != (nums[i] + 1) % n) {
                is_asc = false;
                break;
            }
        }
        
        if (is_asc) {
            if (pos == 0) return 0; 
            return min(pos, n - pos + 2);
        }
        
        bool is_desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[(i + 1) % n] != (nums[i] - 1 + n) % n) {
                is_desc = false;
                break;
            }
        }
        
        if (is_desc) {
            return min(n - pos, pos + 2);
        }
        
        return -1;
    }
};