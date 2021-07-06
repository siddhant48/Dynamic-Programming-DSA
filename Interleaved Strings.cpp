// In the stock market, a person buys a stock and sells it on some future date. Given the stock prices of N days 
// in an array A[ ] and a positive integer K, find out the maximum profit a person can make in at-most K transactions. 
// A transaction is equivalent to (buying + selling) of a 
// stock and new transaction can start only when the previous transaction has been completed.

 bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int n=A.size();
        int m=B.size();
        if(C.size()!=(n+m)) return false;
        int dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 && j==0) 
                dp[i][j]=true;
                else if(i==0 && B[j-1]==C[j-1]) 
                dp[i][j]=dp[i][j-1];
                else if(j==0 && A[i-1]==C[i-1]) 
                dp[i][j]=dp[i-1][j];
                else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1])
                dp[i][j]=dp[i-1][j];
                else if(A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1]) 
                dp[i][j]=dp[i][j-1];
                else if(A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1]) 
                dp[i][j]= dp[i-1][j] || dp[i][j-1];
            }
        }
       return dp[n][m]; 
    }
