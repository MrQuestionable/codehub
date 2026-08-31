class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(i>steps)return false;
            steps=max(steps,i+nums[i]);
        }
    return true;;    
    }
};