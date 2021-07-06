//Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

 int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        if(sum%2!=0) return 0;
        sum=sum/2;
        bool dp[N+1][sum+1];
        for(int i=0;i<=sum;i++)
        dp[0][i]=false;
        for(int i=0;i<=N;i++)
        dp[i][0]=true;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        if(dp[N][sum]) return 1;
        return 0;
        for(int i=1;i<=N;i++)
        {
            if(dp[i][sum]==true) return 1;
        }
        return 0;
    }
