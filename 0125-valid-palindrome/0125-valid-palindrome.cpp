#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isvalid(char c) {
        // Fix: Use '0' and '9' instead of 0 and 9
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            return true;
        }
        return false;
    }

    char convert(char c) {
        // Fix: Use '0' and '9' instead of 0 and 9
        if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            return c;
        }
        else {
            return c + 'a' - 'A';
        }
    }

public:
    bool isPalindrome(string s) {
        int st = 0, e = s.size() - 1;
        
        while(st <= e) {
            // Skip invalid characters on the left
            if (!isvalid(s[st])) {
                st++;
            }
            // Skip invalid characters on the right
            else if (!isvalid(s[e])) {
                e--;
            }
            // Both characters are valid alphanumeric
            else {
                // If they don't match, it's not a palindrome
                if(convert(s[st]) != convert(s[e])) {
                    return false;
                }
                // If they match, move both pointers inward
                st++;
                e--;
            }
        }

        // If the loop finishes without finding mismatches, it is a palindrome
        return true;
    }
};