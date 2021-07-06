// You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. 
//   A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
//   You have to find the longest chain which can be formed from the given set of pairs. 

bool cmp(const val &a,const val &b)
{
    return a.first<b.first;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
sort(p,p+n,cmp);
int dp[n];
for(int i=0;i<n;i++)
dp[i]=1;
for(int i=1;i<n;i++)
{
    for(int j=0;j<i;j++)
    {
        if(p[j].second<p[i].first)
        dp[i]=max(dp[i],dp[j]+1);
    }
}
return dp[n-1];
}
