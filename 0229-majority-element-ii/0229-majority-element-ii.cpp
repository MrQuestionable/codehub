#include<bits/stdc++.h>
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int count=0,count2=0,el1=INT_MIN,el2=INT_MIN;
       int n=nums.size();
       for(int i=0;i<n;i++){
         if(count==0 && nums[i]!=el2){
         el1=nums[i];
         count++;   
         }
         else if(count2==0 && nums[i]!=el1){
            el2=nums[i];
            count2++;
         }
         else if(el1==nums[i]) count++;
         else if(el2==nums[i]) count2++;
         else{
            count--;
            count2--;
         }

       }
       int cnt=0,cnt2=0;
       vector<int> ls;
       for(int i=0;i<n;i++){
        if(nums[i]==el1)cnt++;
        if(nums[i]==el2)cnt2++;
       }
       int mini=int(n/3) + 1;
       if(cnt>=mini){
        ls.push_back(el1);
       }
       if(cnt2>=mini) ls.push_back(el2);
        return ls;

    }
};