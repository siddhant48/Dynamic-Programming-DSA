// Given a set of N items, each with a weight and a value, and a weight limit W. Find the maximum value of a collection containing any of the N 
// items any number of times so that the total weight is less than or equal to W.

 int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[W+1];
        for(int i=0;i<=W;i++) dp[i]=INT_MIN;
        dp[0]=0;
        int maxm=INT_MIN;
        for(int i=1;i<=W;i++)
        {
           // dp[i]=INT_MIN;
            for(int j=0;j<N;j++)
            {
                if(i>=wt[j] && dp[i-wt[j]]!=INT_MIN)
                {
                    dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
                }
            }
            maxm=max(maxm,dp[i]);
        }
        if(maxm==INT_MIN) return 0;
        return maxm;
    }
