class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int aheadbuy=0,aheadsell=0,currbuy=0,currsell=0;
        int profit=0;
        for(int i=n-1;i>=0;i--){
            currbuy=max(-prices[i]+aheadsell,aheadbuy);
            currsell=max(prices[i]+aheadbuy,aheadsell);
            aheadbuy=currbuy;
            aheadsell=currsell;
        }
    return aheadbuy;   
    }
};