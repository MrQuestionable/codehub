class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        stack<int> min_st;
        for(int i=0;i<=nums.size();i++){
            while(!min_st.empty() && (i==nums.size() || nums[min_st.top()]>nums[i])){
                int index = min_st.top();
                min_st.pop();
                
                long long left_bound = min_st.empty() ? -1 : min_st.top();
                long long right_bound = i;
                
                long long subarrays = (index - left_bound) * (right_bound - index);
                ans -= (subarrays * nums[index]);
            }
            min_st.push(i);
        }
        stack<int> max_st;
        for(int i=0;i<=nums.size();i++){
            while(!max_st.empty() && (i==nums.size() || nums[max_st.top()]<nums[i])){
                int index = max_st.top();
                max_st.pop();
                
                long long left_bound = max_st.empty() ? -1 : max_st.top();
                long long right_bound = i;
                
                long long subarrays = (index - left_bound) * (right_bound - index);
                ans += (subarrays * nums[index]);
            }
            max_st.push(i);
        }
    return ans;    
    }
};