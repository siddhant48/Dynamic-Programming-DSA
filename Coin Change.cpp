 Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.


 
 long long int count( int S[], int m, int n )
    {
       
        long long int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++)
        dp[0][i]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=S[i-1])
                dp[i][j]+=dp[i][j-S[i-1]];
            }
        }
        return  dp[m][n];
    }
