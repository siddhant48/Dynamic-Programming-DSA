// Given an array of integers arr[] and a number K.You can pair two numbers of the array if the difference between them 
// is strictly less than K. The task is to find the maximum possible sum of 
// such disjoint pairs. The Sum of P pairs is the sum of all 2P numbers of pairs.

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here   
        sort(arr,arr+N);
        int sum=0;
        int i=N-1,j=N-2;
        while(j>=0)
        {
            if(arr[i]-arr[j]<K)
            {
                sum+=arr[i]+arr[j];
                i=j-1;
                j-=2;
            }
            else{
                i--;
                j--;
            }
        }
        return sum;
    }
