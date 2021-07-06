// Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an 
// egg such that it doesn't break. You have to determine the minimum number of attempts you need in order 
//   find the critical floor in the worst case while using the best strategy.There are few rules given below. 

// An egg that survives a fall can be used again.
// A broken egg must be discarded.
// The effect of a fall is the same for all eggs.
// If the egg doesn't break at a certain floor, it will not break at any floor below.
// If the eggs breaks at a certain floor, it will break at any floor above.

int eggDrop(int n, int k) 
{
    // your code here
    int dp[n+1][k+1];
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=0;
        dp[i][1]=1;
    }
    for(int i=1;i<=k;i++)
    {
        dp[1][i]=i;
        dp[0][i]=0;
    }
    //int m=INT_MAX;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            dp[i][j]=INT_MAX;
            for(int h=1;h<j;h++)
            {
                int temp=1+max(dp[i-1][h-1],dp[i][j-h]);
                dp[i][j]=min(dp[i][j],temp);
            }
            //m=min(m,dp[i][j]);
        }
    }
    return dp[n][k];
}
