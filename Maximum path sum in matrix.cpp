// Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

// Matrix [r+1] [c]
// Matrix [r+1] [c-1]
// Matrix [r+1] [c+1]
// Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int dp[N][N];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<N;i++)
        {
            dp[0][i]=Matrix[0][i];
        }
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(j==N-1)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+Matrix[i][j];
                else if(j==0)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+Matrix[i][j];
                else
                dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]))+Matrix[i][j];
            }
        }
         int maxm=0;
    for(int i=0;i<N;i++)
    {
        maxm=max(maxm,dp[N-1][i]);
    }
    return maxm;
    }
