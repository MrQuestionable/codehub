class Solution {
public:
    vector<int> f(int row){
        long long a=1;
        vector<int> ds;
        ds.push_back(1);
        for(int col=1;col<row;col++){
            a=a*(row-col);
            a=a/(col);
            ds.push_back(a);
        }
    return ds;    
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(f(i));
        }
    return ans;    
    }
};