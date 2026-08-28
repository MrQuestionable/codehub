class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),leftm=0,rightm=0,total=0,l=0,r=n-1;
        while(l<r){
            if(height[l]<=height[r]){
                if(leftm>height[l]){
                    total += leftm-height[l];
                }
                else{
                    leftm=height[l];
                }
                l++;
            }
            else{
                if(rightm>height[r]){
                    total += rightm-height[r];
                }
                else{
                    rightm=height[r];
                }
                r--;
            }
        }
    return total;    
    }
};