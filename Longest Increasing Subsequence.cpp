//Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

 int longestSubsequence(int n, int a[])
    {
       vector<int>dp(n+1);
        dp[0]=INT_MIN;
       for(int i=1;i<=n;i++) dp[i]=INT_MAX;
      
       for(int i=0;i<n;i++)
       {
           int idx=upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
           if(a[i]>dp[idx-1])
           dp[idx]=min(dp[idx],a[i]);
       }
       int ans=0;
       for(int i=n;i>=1;i--)
       {
           if(dp[i]!=INT_MAX)
           {
               ans=i;
               break;
           }
       }
       return ans;
    }
