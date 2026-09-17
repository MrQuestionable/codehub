class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> cur(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<=1;b++){
                for(int cap=1;cap<=2;cap++){
                    if(b==1){
                        cur[b][cap]=max(-prices[i]+after[0][cap],after[1][cap]);
                    }
                    else{
                        cur[b][cap]=max(prices[i]+after[1][cap-1],after[0][cap]);
                    }
                    
                }
            after=cur;    
            }
        }
    return after[1][2];    
    }
};