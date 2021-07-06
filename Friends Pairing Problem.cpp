Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. 
Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.

int countFriendsPairings(int n) 
    { 
        // code here
         long long int mod=1e9+7;
       long long dp[n+1];
       dp[0]=0;
       dp[1]=1;
       dp[2]=2;
       for(int i=3;i<=n;i++)
       dp[i]=dp[i-1]%mod+(dp[i-2]*(i-1))%mod;
       return dp[n]%mod;
    }
