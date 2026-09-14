class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totsum = 0;
        for(int num : nums) totsum += num;
        if(totsum - abs(target) < 0 || (totsum + target) % 2 != 0) {
            return 0;
        }
        int s1 = (totsum + target) / 2;
        vector<int> prev(s1+1,0);

        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(nums[0] != 0 && nums[0] <= s1) {
            prev[nums[0]] = 1;
        }
        for(int i=1;i<n;i++){
            for(int t=s1;t>=0;t--){
                int notake = prev[t];
                int take = 0;
                if(t >= nums[i]){
                take = prev[t-nums[i]];
                }
            prev[t]=take+notake;   
            }
        }
    return prev[s1];       
    }
};