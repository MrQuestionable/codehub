class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
 
        int n = nums.size();
        vector<int>ans(n);
 
        int preprod = 1;
        for(int i = 0; i<n; i++){
            ans[i] = preprod;
            preprod *= nums[i];
        }
 
        int suffprod = 1;
        for(int i = n-1; i>=0; i--){
            ans[i] *= suffprod;
            suffprod *= nums[i];
        }
 
        return ans;
    }
};