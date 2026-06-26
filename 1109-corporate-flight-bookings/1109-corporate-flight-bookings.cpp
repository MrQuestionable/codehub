class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
 
        vector<int>pre(n, 0);
 
        for(auto x: bookings){
            int l = x[0];
            int r = x[1];
            int val = x[2];
 
            pre[l - 1] += val;
            if(r < n) pre[r] += -val;
        }
 
        for(int i = 1; i < pre.size(); i++){
            pre[i] += pre[i-1];
        }
 
        return pre;
        
    }
};