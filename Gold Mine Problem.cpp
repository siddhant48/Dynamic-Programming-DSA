// Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer 
// which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

// to the cell diagonally up towards the right 
// to the right
// to the cell diagonally down towards the right
// Find out maximum amount of gold which he can collect.

 int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int dp[n][m];
        for(int i=0;i<n;i++)
        {
            dp[i][0]=M[i][0];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a=0,b=0,c=0;
                 if(i-1>=0) a=dp[j][i-1]+M[j][i];
                 if(j+1<n && i-1>=0)   b=dp[j+1][i-1]+M[j][i];
                 if(j-1>=0 && i-1>=0)   c=dp[j-1][i-1]+M[j][i];
                 dp[j][i]=max(a,max(b,c));
            }    
        }
        int maxm=INT_MIN;
        for(int i=0;i<n;i++)
        maxm=max(maxm,dp[i][m-1]);
        return maxm;
    }
