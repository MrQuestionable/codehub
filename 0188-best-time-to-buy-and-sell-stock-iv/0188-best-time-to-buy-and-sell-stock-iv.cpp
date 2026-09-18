class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(2*k,0);
        for(int i=0;i<2*k;i+=2){
            dp[i]=-1e9;
        }
        for(int price:prices){
            for(int j=0;j<2*k;j++){
                if(j==0){
                   dp[j]=max(-price,dp[j]);
                }
                else if(j%2==0){
                    dp[j]=max(dp[j],dp[j-1]-price);
                }
                else{
                    dp[j]=max(price+dp[j-1],dp[j]);
                }
            }
        }
    return dp[2*k-1];    
    }
};