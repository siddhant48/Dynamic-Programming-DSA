// Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words. 

int wordBreak(string s, vector<string> &t) {
    //code here
   int dp[s.size()+1];
   memset(dp,false,sizeof(dp));
   dp[0]=true;
   for(int i=1;i<=s.size();i++)
   {
       for(int j=0;j<t.size();j++)
       {
           if(dp[i-1]==true && s.substr(i-1,t[j].size())==t[j])
           dp[i+t[j].size()-1]=true;
       }
   }
   return dp[s.size()];
}
