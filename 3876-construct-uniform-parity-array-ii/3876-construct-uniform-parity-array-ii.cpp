class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if(nums1.empty())return true;
        bool haseven=false,hasodd=false;
        int min=nums1[0];
        for(int num:nums1){
            if(num%2==0)haseven=true;
            else hasodd=true;
            if(num<min){
                min=num;
            }
        }
    if(!haseven||!hasodd)return true;
    return min%2!=0;    
    }
};