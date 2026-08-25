#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void solve(int col, int n, vector<vector<string>> &ans, vector<string> &ds,
               vector<int> &leftrow, vector<int> &updia, vector<int> &lowdia) {
        
        if (col == n) {
            ans.push_back(ds);
            return;
        }
        
        for (int row = 0; row < n; row++) {
            if (leftrow[row] == 0 && updia[n - 1 + col - row] == 0 && lowdia[row + col] == 0) {
                ds[row][col] = 'Q';
                leftrow[row] = 1;
                updia[n - 1 + col - row] = 1; 
                lowdia[row + col] = 1;        
                solve(col + 1, n, ans, ds, leftrow, updia, lowdia);
                ds[row][col] = '.';
                leftrow[row] = 0;
                updia[n - 1 + col - row] = 0; 
                lowdia[row + col] = 0;        
            }
        }
    } 
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> ds(n, s);
        vector<int> leftrow(n, 0), updia(2 * n - 1, 0), lowdia(2 * n - 1, 0);
        solve(0, n, ans, ds, leftrow, updia, lowdia);
        return ans;
    }
};