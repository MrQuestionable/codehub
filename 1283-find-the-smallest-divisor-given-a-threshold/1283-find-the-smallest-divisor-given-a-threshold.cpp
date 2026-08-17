#include<bits/stdc++.h>
class Solution {
public:
    double checkdivisor(vector<int> &nums, int mid){
        double sum=0;
        for(int i=0; i<nums.size();i++){
            sum+=ceil((double)nums[i]/(double)(mid));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=0, high=*max_element(nums.begin(),nums.end()), ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(checkdivisor(nums,mid)<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};