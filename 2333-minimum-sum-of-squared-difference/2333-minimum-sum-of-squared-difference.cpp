class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        
        long long total_diff = 0;
        int max_diff = 0;
        vector<int> diff(n);
        
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total_diff += diff[i];
            max_diff = max(max_diff, diff[i]);
        }
        
        if (k >= total_diff) return 0;
        
        vector<long long> bucket(max_diff + 1, 0);
        for (int i = 0; i < n; i++) {
            bucket[diff[i]]++;
        }
        
        for (int d = max_diff; d > 0; d--) {
            if (bucket[d] > 0) {
                long long reductions = min(bucket[d], k);
                
                bucket[d] -= reductions;       
                bucket[d - 1] += reductions;  
                k -= reductions;              
                
                if (k == 0) break; 
            }
        }
        long long min_sum = 0;
        for (long long d = 1; d <= max_diff; d++) {
            if (bucket[d] > 0) {
                min_sum += bucket[d] * d * d;
            }
        }
        
        return min_sum;
    }
};