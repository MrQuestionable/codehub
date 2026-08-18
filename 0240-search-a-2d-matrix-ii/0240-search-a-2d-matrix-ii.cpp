class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ro=0, col=m-1;
        while(ro<n && col>=0){
            if(matrix[ro][col]==target){
                return true;
            }
            else if(matrix[ro][col]>target)col--;
            else ro++;
        }
        return false;
    }
};