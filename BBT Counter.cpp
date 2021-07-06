// Given a height h, count the maximum number of balanced binary trees possible with height h. Print the result modulo 109 + 7.
// Note : A balanced binary tree is one in which for every node, the difference between heights of left and right subtree is not more than 1.

 long long int countBT(int h) { 
        // code here
        long long int dp[h+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=3;
        long long int mod=1e9+7;
        for(int i=3;i<=h;i++)
        {
            long long int a=dp[i-1]*dp[i-1]%mod;
            long long int b=2*dp[i-1]*dp[i-2]%mod;
            dp[i]=(a+b)%mod;
        }
        return dp[h];
    }
