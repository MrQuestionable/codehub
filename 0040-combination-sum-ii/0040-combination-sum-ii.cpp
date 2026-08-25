class Solution {
public:
    void checsum(int ind, vector<int>& ds,int target, vector<int>& arr,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1])continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            checsum(i+1,ds,target-arr[i],arr,ans);
            ds.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        checsum(0,ds,target,candidates,ans);
        return ans; 
    }
};