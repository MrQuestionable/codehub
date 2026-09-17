class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int currbuy=INT_MIN,currsell=0,afterbuy=INT_MIN,aftersell=0;
        for(auto it:prices){
            currbuy=max(currbuy,-it);
            currsell=max(it+currbuy,currsell);
            afterbuy=max(afterbuy,currsell-it);
            aftersell=max(aftersell,it+afterbuy);
        }
    return aftersell;  
    }
};