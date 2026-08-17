class Solution {
public:
    bool possible(vector<int>&weights, int limit, int dayLimit){
 
        int day = 1,currWt = 0; 
        for(auto x: weights){
            if(currWt + x > limit){
                day++;
                currWt = 0;
            }
            currWt += x;
        }
        return day <= dayLimit;
 
 
    }
    int shipWithinDays(vector<int>& weights, int days) {
 
        int lo = *max_element(weights.begin(), weights.end()),ans = -1;;
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while(lo <= hi){
 
            int mid = lo + (hi - lo) / 2;
 
            if(possible(weights, mid, days)){
                hi = mid - 1;
                ans = mid;
            }
            else{
                lo = mid + 1;
            }
        }
 
        return ans;
        
    }
};