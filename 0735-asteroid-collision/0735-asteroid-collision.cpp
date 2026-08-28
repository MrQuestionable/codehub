#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int a : asteroids) {
            bool destroyed = false;
            while (!st.empty() && st.back() > 0 && a < 0) {
                if (st.back() < abs(a)) {
                    st.pop_back();
                    continue; 
                }
                else if (st.back() == abs(a)) {
                    st.pop_back();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) {
                st.push_back(a);
            }
        }
        
        return st;
    }
};