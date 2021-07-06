Given a string, find the length of the longest repeating subsequence such that the two subsequences don't have 
same string character at the same position, i.e., any i'th character in the 
two subsequences shouldn't have the same index in the original string.

	int LongestRepeatingSubsequence(string str){
		    // Code here
		    string s1=str,s2=str;
		    int n=str.size();
		    int dp[n+1][n+1];
		    memset(dp,0,sizeof(dp));
		    for(int i=1;i<=n;i++)
		    {
		        for(int j=1;j<=n;j++)
		        {
		            if(s1[i-1]==s2[j-1] && i!=j)
		            dp[i][j]=dp[i-1][j-1]+1;
		            else{
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		    return dp[n][n];
		}
