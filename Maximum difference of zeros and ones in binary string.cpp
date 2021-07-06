// Given a binary string of 0s and 1s. The task is to find the maximum difference of the number of 0s and the number of 1s
//   (number of 0s – number of 1s) in the substrings of a string.

// Note: In the case of all 1s, the answer will be -1.

	int maxSubstring(string S)
	{
	    // Your code goes here
	    int n=S.size();
	    int a[n];
	    int zero=0,one=0;
	    for(int i=0;i<n;i++)
	    {
	        if(S[i]=='0') zero++;
	        else one++;
	        a[i]=zero-one;
	    }
	    int val=-1,minm=0;
	    for(int i=0;i<n;i++)
	    {
	        val=max(val,a[i]-minm);
	        minm=min(minm,a[i]);
	    }
	    return val;
	}
