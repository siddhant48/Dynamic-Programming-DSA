//Given an array A[] of size N, find the longest subsequence such that difference between adjacent elements is one.

 int longestSubsequence(int N, int A[])
    {
        // code here
        int dp[N];
        for(int i=0;i<N;i++)
        dp[i]=1;
        int maxm=1;
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(abs(A[j]-A[i])==1)
                dp[i]=max(dp[i],dp[j]+1);
            }
            maxm=max(maxm,dp[i]);
        }
        return maxm;
    }
