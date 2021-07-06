Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut
length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

 int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int dp[n+1];
        for(int i=0;i<=n;i++) dp[i]=-1;
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            int a=-1,b=-1,c=-1;
            if(i-x>=0 && dp[i-x]!=-1) a=dp[i-x]+1;
            if(i-y>=0 && dp[i-y]!=-1) b=dp[i-y]+1;
            if(i-z>=0 && dp[i-z]!=-1) c=dp[i-z]+1;
            dp[i]=max(a,max(b,c));
            
        }
        if(dp[n]==-1) return 0;
        return dp[n];
    }
