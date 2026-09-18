class Solution {
public:
    static bool comp(const string &s1, const string &s2){
        return s1.size() < s2.size();
    }

    bool possible(const string &s1, const string &s2){
        if(s1.size() != s2.size() + 1) return false;
        
        int first = 0, second = 0;
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first++;
                second++;
            }
            else {
                first++;
            }
        }
        return first == s1.size() && second == s2.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                
                if(possible(words[i], words[j]) && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
            }
        }
        
        return maxi;    
    }
};