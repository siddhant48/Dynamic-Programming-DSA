// You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

// In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

// You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally.

long long maximumAmount(int arr[], int n) 
{
    // Your code here
    int dp[n][n];
    for(int gap=0;gap<n;gap++)
    {
        for(int i=0;i<n-gap;i++)
        {
            int j=i+gap;
            if(i==j)
            dp[i][j]=arr[i];
            else dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];
    int val=(sum+dp[0][n-1])/2;
    return val;
}
