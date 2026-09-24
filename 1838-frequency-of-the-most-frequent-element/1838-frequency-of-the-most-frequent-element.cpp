class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int left = 0;
        long long window_sum = 0; 
        int max_freq = 0;
        for (int right = 0; right < nums.size(); ++right) {
            window_sum += nums[right];
            long long window_len = right - left + 1;
            long long operations_needed = (nums[right] * window_len) - window_sum;
            
            while (operations_needed > k) {
                window_sum -= nums[left];
                left++;
                window_len = right - left + 1;
                operations_needed = (nums[right] * window_len) - window_sum;
            }
            max_freq = max(max_freq, (int)window_len);
        }
        
        return max_freq;
    }
};