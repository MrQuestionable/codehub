class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long current_val = 1;  
        
        for (int i = 0; i <= rowIndex; i++) {
            ans.push_back(current_val);
            current_val = current_val * (rowIndex - i) / (i + 1);
        }
        
        return ans;
    }
};
