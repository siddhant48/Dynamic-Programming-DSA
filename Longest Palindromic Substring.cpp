//Given a string s, return the longest palindromic substring in s.

 string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n];
        int maxm=0,start=-1;
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0;i<n-gap;i++)
            {
                int j=i+gap;
                if(i==j)
                    dp[i][j]=1;
                else if(s[i]==s[j])
                {
                    if(i+1==j)
                        dp[i][j]=2;
                    else if(dp[i+1][j-1]!=0)
                        dp[i][j]=2+dp[i+1][j-1];
                    else dp[i][j]=0;
                }
                else dp[i][j]=0;
                if(dp[i][j]>maxm){
                    maxm=max(maxm,dp[i][j]);
                    start=i; 
                }
              
            }
        }
        return s.substr(start,maxm);
    }
