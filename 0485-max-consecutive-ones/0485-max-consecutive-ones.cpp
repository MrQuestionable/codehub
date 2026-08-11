class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int curr = 0;
 
        for(auto x: nums){
 
            if(x == 1){
                curr++;
            }
            else{
                curr = 0;
            }
 
            ans = max(ans, curr);
        
        }
        return ans;
    }       
};