#include<bits/stdc++.h>
class Solution {
public:
    string frequencySort(string s) {
       int frequency=INT_MIN;
       unordered_map<char, int> mp;
       for(char ch:s){
        mp[ch]++;
       }
       vector<pair<char,int>> freq(mp.begin(),mp.end());
       sort(freq.begin(), freq.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second; 
        });
        string result="";
        for(auto pair:freq){
            result.append(pair.second,pair.first);
        }
        return result;
    }
};