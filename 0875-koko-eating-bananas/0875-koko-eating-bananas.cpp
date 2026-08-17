#include<bits/stdc++.h>
class Solution {
public:
    int max_el(vector<int> &piles){
        int maxe=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxe=max(maxe,piles[i]);
        }
        return maxe;
    }
    double check(vector<int> &piles, int hourly){
        double total=0;
        for(int i=0; i<piles.size(); i++){
            total+=ceil((double)piles[i]/(double)hourly);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int m=max_el(piles);
        int low=1, high=m,k=INT_MAX;
        while(low<=high){
            int mid=low + (high-low)/2;
            double total=check(piles,mid);
            if(total<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};