// Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:

// Insert
// Remove
// Replace

 int editDistance(string s, string t) {
        // Code here
        int n=s.size();
        int m=t.size();
        int dp[n+1][m+1];
        for(int i=0;i<=m;i++)
        dp[0][i]=i;
        for(int i=0;i<=n;i++)
        dp[i][0]=i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
                }
            }
        }
        return dp[n][m];
    }
 
