class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>& ans,int color,int drow[],int dcol[],int colr){
        int n=image.size();
        int m=image[0].size();
        ans[row][col]=color;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==colr && ans[nrow][ncol]!=color){
                dfs(nrow,ncol,image,ans,color,drow,dcol,colr);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int colr=image[sr][sc];
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>> ans=image;
        dfs(sr,sc,image,ans,color,drow,dcol,colr);
        return ans;
    }
};