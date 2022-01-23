class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int n = prices.size();
        //f[i][0] 手上持有股票的最大收益
        //f[i][1] 手上没有股票，并且处于冷冻期的累计最大收益   
        //f[i][2] 手上没有股票，并且不在冷冻期的累计最大收益
        vector<int> dp(3);
        dp[0] = -prices[0];
        for(int i = 1; i < n; i++ ){
            int temp0 = max(dp[0],dp[2] - prices[i]);
            int temp1 = dp[0] + prices[i];
            int temp2 = max(dp[1],dp[2]);
            dp[0] = temp0;
            dp[1] = temp1;
            dp[2] = temp2;
        }
        return max(dp[1],dp[2]);
    }
};
