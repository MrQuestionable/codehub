class Solution {
public:
    int fn(vector<int>& nums, int n, int target){
        int low=0, high=n-1,first=-1;
        
        while(low<=high){
            int mid=low + (high-low)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;   
            }
            else if(target>nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return first; 
    }
    int fn1(vector<int>& nums, int n, int target){
        int low=0, high=n-1,last=-1;
        
        while(low<=high){
            int mid=low + (high-low)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;   
            }
            else if(target>nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return last; 
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first = fn(nums,n,target);
        if(first==-1)return {-1,-1};
        int last = fn1(nums,n ,target);
        return {first,last};   
    }
};