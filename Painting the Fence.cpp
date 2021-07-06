// Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent 
// posts have the same color. Since answer can be large return it modulo 10^9 + 7.

long long countWays(int n, int k){
        // code here
        long long dp[n+1];
        dp[0]=0;
        dp[1]=k;
        dp[2]=k*k;
        long long  mod=1e9+7;
        for(int i=3;i<=n;i++)
        {
           
            dp[i]=((k-1)*(dp[i-1]%mod+dp[i-2]%mod))%mod;
        }
        return dp[n];
    }
