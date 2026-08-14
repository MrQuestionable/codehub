class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     int left=m-1;
     int right=n-1;
     int p=m+n-1;
     while(right>=0){
        if(left>=0 && nums1[left]>nums2[right]){
            swap(nums1[left],nums1[p]);
            left--;
        }
        else{
            nums1[p]=nums2[right];
            right--;
        }
        p--;
     }
      
    }
};