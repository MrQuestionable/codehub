class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        int currbuy=0,currsell=0,aheadbuy=0,aheadsell=0;
        for(int i=n-1;i>=0;i--){
            currbuy=max(-prices[i]+aheadsell,aheadbuy);
            currsell=max(prices[i]-fee+aheadbuy,aheadsell);
            aheadbuy=currbuy;
            aheadsell=currsell;
        }
    return aheadbuy;    
    }
};