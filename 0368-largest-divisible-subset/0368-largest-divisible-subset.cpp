class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> curr(n, 1), hash(n);
        
        sort(nums.begin(), nums.end());
        
        int max_len = 1;
        int last_index = 0;
        
        for(int i = 0; i < n; i++){
            hash[i] = i; 
            
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && 1 + curr[j] > curr[i]){
                    curr[i] = 1 + curr[j];
                    hash[i] = j; 
                }
            }
            if(curr[i] > max_len){
                max_len = curr[i];
                last_index = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[last_index]);
        while(hash[last_index] != last_index){
            last_index = hash[last_index];      
            temp.push_back(nums[last_index]);   
        }
        
        reverse(temp.begin(), temp.end());
        
        return temp;
    }
};