class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int k=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i=i+1;
                k++;
            }
        }
        cout<<k<<endl;
        return i;
    }
};