// Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.
// Note: You have to return the answer module 109+7;

int countPS(string str)
{
   //Your code here
   int n=str.size();
   int dp[n][n];
    memset(dp,0,sizeof(dp));
   int count=0;
   for(int gap=0;gap<n;gap++)
   {
       for(int i=0;i<n-gap;i++)
       {
           int j=i+gap;
           if(i==j)
           {
               dp[i][j]=1;
              
           }
          else if(str[i]==str[j])
          {
              dp[i][j]=dp[i][j-1]+dp[i+1][j]+1;
          }
          else dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
       }
   }
   return dp[0][n-1];
}
