class Solution {
public:
    int largestelem(vector<vector<int>> &mat, int n, int m,int col){
        int max=-1, index=-1;
        for(int i=0; i<n;i++){
            if(mat[i][col]>max){
                max=mat[i][col];
                index=i;
            }
        }
        return index;
    } 
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int lo=0, hi=m-1;
        while(lo<=hi){
            int mid=lo + (hi-lo)/2;
            int maxrow = largestelem(mat, n , m, mid);
            int left=mid-1 >=0? mat[maxrow][mid-1]: -1;
            int right=mid+1 <m? mat[maxrow][mid+1]: -1;
            if(mat[maxrow][mid]>left && mat[maxrow][mid]>right)return {maxrow,mid};
            else if(mat[maxrow][mid]<left)hi=mid-1;
            else lo=mid+1;
        }
        return {-1,-1};
    }
};