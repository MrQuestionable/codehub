#include<bits/stdc++.h>
class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;
        
        // 1. Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // 2. Check for optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // 3. Process digits and check for overflow
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // 4. Overflow/Underflow check BEFORE we multiply by 10
            // INT_MAX is 2147483647. INT_MAX / 10 is 214748364.
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        // 5. Apply the sign and return
        return result * sign;
    }
};