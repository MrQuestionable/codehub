class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        // 1. Create our target reference
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        int total_sum = 0;
        
        // 2. Iterate through all possible divisors 'k'
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            
            bool is_valid_k = true;
            
            // 3. Check every block of size k
            for (int i = 0; i < n; i += k) {
                int drop_idx = -1;
                int drops = 0;
                
                // Find how many times the ascending order breaks in this block
                for (int j = 0; j < k - 1; j++) {
                    if (nums[i + j] > nums[i + j + 1]) {
                        drops++;
                        drop_idx = j;
                    }
                }
                
                // If it breaks more than once, or if the wrap-around is invalid, it's not a cyclic shift
                if (drops > 1 || (drops == 1 && nums[i + k - 1] > nums[i])) {
                    is_valid_k = false;
                    break;
                }
                
                // 4. Verify the un-rotated block perfectly matches the globally sorted array
                int start_offset = (drops == 0) ? 0 : (drop_idx + 1);
                
                for (int j = 0; j < k; j++) {
                    int original_val = nums[i + (start_offset + j) % k];
                    int target_val = sorted_nums[i + j];
                    
                    if (original_val != target_val) {
                        is_valid_k = false;
                        break;
                    }
                }
                
                if (!is_valid_k) break;
            }
            
            if (is_valid_k) {
                total_sum += k;
            }
        }
        
        return total_sum;
    }
};