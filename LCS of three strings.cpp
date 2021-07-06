//Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    int dp[n1+1][n2+1][n3+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            for(int k=1;k<=n3;k++)
            {
                if(A[i-1]==B[j-1] && B[j-1]==C[k-1])
                {
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                }
                else {
                    int a=max(dp[i][j][k-1],dp[i-1][j][k]);
                    int b=max(dp[i][j-1][k],dp[i][j][k-1]);
                    dp[i][j][k]=max(a,b);
                }
            }
        }
    }
    return dp[n1][n2][n3];
}
