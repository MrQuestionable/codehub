class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0],prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1)take+=prev2;
            int notake=prev;
            int curr=max(take,notake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};