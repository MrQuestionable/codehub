class Solution {
public:
    bool possible(vector<int>&nums, int limit, int k){
        int subarray = 1,curr = 0;
        for(auto x: nums){
 
            if(curr + x > limit){
                subarray++;
                curr = 0;
            }
            curr += x;
        }
 
        return subarray <= k;
 
    }
 
    int splitArray(vector<int>& nums, int k) {
 
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
 
        int ans = -1;
 
        while(lo <= hi){
            int mid = lo + (hi - lo)/ 2;
 
            if(possible(nums, mid, k)){
                hi = mid - 1;
                ans = mid;
            }
            else{
 
                lo = mid + 1;
 
            }
        }
 
        return ans;
        
    }
};