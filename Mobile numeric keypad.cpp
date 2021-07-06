// Given the mobile numeric keypad. You can only press buttons that are up, left, right, or down to the current button. 
//   You are not allowed to press bottom row corner buttons (i.e. * and # ). Given a number N,
// the task is to find out the number of possible numbers of the given length.

	long long getCount(int N)
	{
		// Your code goes here
		long long  dp[N+1][10];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=9;i++)
		dp[1][i]=1;
		for(int i=2;i<=N;i++)
		{
		    for(int j=0;j<=9;j++)
		    {
		        if(j==1) dp[i][j]= dp[i-1][2]+dp[i-1][4]+dp[i-1][j];
		        else if(j==2) dp[i][j]= dp[i-1][1]+dp[i-1][3]+dp[i-1][5]+dp[i-1][j];
		        else if(j==3) dp[i][j]=dp[i-1][2]+dp[i-1][6]+dp[i-1][j];
		        else if(j==4) dp[i][j]= dp[i-1][1]+dp[i-1][7]+dp[i-1][5]+dp[i-1][j];
		        else if(j==5) dp[i][j]=dp[i-1][4]+dp[i-1][6]+dp[i-1][2]+dp[i-1][8]+dp[i-1][j];
		        else if(j==6) dp[i][j]=dp[i-1][3]+dp[i-1][9]+dp[i-1][5]+dp[i-1][j];
		        else if(j==7) dp[i][j]=dp[i-1][4]+dp[i-1][8]+dp[i-1][j];
		        else if(j==8) dp[i][j]=dp[i-1][7]+dp[i-1][9]+dp[i-1][5]+dp[i-1][0]+dp[i-1][j];
		        else if(j==9) dp[i][j]=dp[i-1][8]+dp[i-1][6]+dp[i-1][j];
		        else if(j==0) dp[i][j]=dp[i-1][8]+dp[i-1][j];
		    }
		}
		long long  sum=0;
		for(int i=0;i<=9;i++)
		sum+=dp[N][i];
		return sum;
	}
