class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long MOD = 1e9 + 7;
        long long total_sum = 0;
        
        stack<int> st; 
        
        for (int i = 0; i <= n; i++) {
            int curr_val = (i == n) ? 0 : arr[i];
            
            while (!st.empty() && arr[st.top()] > curr_val) {
                int index = st.top();
                st.pop();
                
                int left_bound = st.empty() ? -1 : st.top();
                int right_bound = i;
                
                long long left_count = index - left_bound;
                long long right_count = right_bound - index;
                long long total_subarrays = (left_count * right_count) % MOD;
                long long contribution = (total_subarrays * arr[index]) % MOD;
                
                total_sum = (total_sum + contribution) % MOD;
            }
            
            st.push(i);
        }
        
        return total_sum;
    }
};