// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 int maxProfit(vector<int>& prices) {
        int k=2;
        int n=prices.size();
        int dp[k+1][n];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=k;i++)
        {
            int temp=INT_MIN;
            for(int j=1;j<n;j++)
            {
                temp=max(temp,dp[i-1][j-1]-prices[j-1]);
                dp[i][j]=max(dp[i][j-1],temp+prices[j]);
            }
        }
        return dp[k][n-1];
    }
 
