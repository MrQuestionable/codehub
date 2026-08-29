class Solution {
public:
    int peak(vector<int>& nums,int k){
        if(k<0) return 0;
        int left=0,n=nums.size(),ones=0,count=0;

        for(int right=0;right<n;right++){
            if(nums[right]==1){
                ones++;
            }

            while(ones>k){
                if(nums[left]==1){
                    --ones;
                }
                left++;
            }

            count+=right-left+1;
        }

        return count;
    }


    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return peak(nums,goal)-peak(nums,goal-1);
    }
};