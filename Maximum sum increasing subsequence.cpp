//Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.

	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int dp[n];
	    dp[0]=arr[0];
	    int maxm=dp[0];
	    for(int i=1;i<n;i++)
	    {
	        dp[i]=arr[i];
	        for(int j=0;j<i;j++)
	        {
	            if(arr[j]<arr[i])
	            {
	                dp[i]=max(dp[i],dp[j]+arr[i]);
	            }
	        }
	        maxm=max(maxm,dp[i]);
	    }
	    return maxm;
	}  
