class Solution {
public:
    string frequencySort(string s) {
        map<char, int > freq ;
        string ans;
        vector<pair<char, int > > v;
        for (char c:s){
            freq[c]++;
        }
        for(auto a: freq){
            v.push_back(a);

        }
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
             return a.second > b.second;
        });
        for(int i = 0 ; i < v.size(); i++){
            for(int j = 0 ; j < v[i].second; j++){
                ans+=(v[i].first);
            }
        }
        return ans;
        
    }
};