// Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string
// of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.

int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        int dp[n];
        bool p[n][n];
        memset(p,false,sizeof(p));
        for(int i=0;i<n;i++)
        {
            int m=i;
            for(int j=0;j<=i;j++)
            {
                if(str[i]==str[j] && (i-j<2 || p[j+1][i-1]==true))
                {
                    p[j][i]=true;
                    m= min(m,j==0?0:(dp[j-1]+1));
                }
            }
            dp[i]=m;
        }
        return dp[n-1];
        
    }
