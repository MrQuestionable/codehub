class Solution {
    int mod=1000000007; 
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd_count = 0;
        int even_count = 1; 
        int current_sum = 0;
        long long total_subarrays = 0;
        
        for (int num : arr) {
            current_sum += num;
            
            if (current_sum % 2 == 0) {
                total_subarrays += odd_count;
                even_count++;
            } else {
                total_subarrays += even_count;
                odd_count++;
            }
        }
        
        return total_subarrays % mod;    
    }
};