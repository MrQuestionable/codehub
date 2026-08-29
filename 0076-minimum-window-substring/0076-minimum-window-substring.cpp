#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int count = 0, minl = INT_MAX, r = 0, l = 0, sind = -1;
        
        // Populate the frequency map with characters from t
        for(char c : t){
            mp[c]++;
        }
        
        while(r < s.size()){
            // If the character is needed, increase our valid character count
            if(mp[s[r]] > 0){
                count++;
            }
            // UNCONDITIONALLY decrement. Extra characters will just become negative.
            mp[s[r]]--; 
            
            // When we have a valid window containing all characters
            while(count == t.size()){
                
                // Only update the minimum window if the current one is smaller
                if (r - l + 1 < minl) {
                    minl = r - l + 1;
                    sind = l;
                }
                
                // Shrink the window from the left
                // Since we are removing s[l] from the window, we add it back to the map
                mp[s[l]]++;
                
                // If it becomes > 0, it means we just removed a strictly required character
                if(mp[s[l]] > 0) {
                    count--;
                }
                
                // MOVE THE LEFT POINTER! (Fixes infinite loop)
                l++;
            }
            
            r++;
        }
        
        // Fix ternary operator syntax (, to :)
        return sind == -1 ? "" : s.substr(sind, minl);
    }
};