//Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

 int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int p[n];
        p[0]=arr[0];
        for(int i=1;i<n;i++)
        p[i]=p[i-1]+arr[i];
        int minm=0,maxm=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxm=max(maxm,p[i]-minm);
            minm=min(minm,p[i]);
        }
        return maxm;
    }
