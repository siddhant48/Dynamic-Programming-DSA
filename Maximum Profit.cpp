// In the stock market, a person buys a stock and sells it on some future date. Given the stock prices of N 
// days in an array A[ ] and a positive integer K, find out the maximum profit a person can make in at-most K transactions. 
//   A transaction is equivalent to (buying + selling) of a 
// stock and new transaction can start only when the previous transaction has been completed.

int maxProfit(int K, int N, int A[]) {
        // code here
       int dp[K+1][N];
       memset(dp,0,sizeof(dp));
       int maxm=0;
       for(int i=1;i<=K;i++)
       {
           int temp=INT_MIN;
           for(int j=1;j<N;j++)
           {
              temp=max(temp,dp[i-1][j-1]-A[j-1]);
              dp[i][j]=max(dp[i][j-1],temp+A[j]);
           }
       }
       return dp[K][N-1];
    }
