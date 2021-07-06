

// Given an array of N integers arr[] where each element represents the max number of steps that can be 
// made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
// Note: Return -1 if you can't reach the end of the array.

 int minJumps(int arr[], int n){
        // Your code here
        int maxmCurr=0,maxmNext=0;
        int jump=0;
        for(int i=0;i<n-1;i++)
        {
            maxmNext=max(maxmNext,i+arr[i]);
            if(i==maxmCurr)
            {
                maxmCurr=maxmNext;
                jump++;
            }
            if(maxmCurr>=n-1)
            break;
        }
        if(maxmCurr<n-1) return -1;
        return jump;
    }
