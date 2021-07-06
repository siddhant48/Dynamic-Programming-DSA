//Given a 2D matrix M of dimensions RxC. Find the maximum sum subarray in it.


int kadane(vector<int>a,int n)
{
    int prefix[n];
    prefix[0]=a[0];
    for(int i=1;i<n;i++)
    prefix[i]=prefix[i-1]+a[i];
    int minm=0;
    int val=INT_MIN;
    for(int i=0;i<n;i++)
    {
        val=max(val,prefix[i]-minm);
        minm=min(minm,prefix[i]);
    }
    return val;
}
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int maxm=INT_MIN;
     for(int i=0;i<R;i++)
     {
        // int temp[C]={0};
         vector<int>temp(C,0);
         for(int j=i;j<R;j++)
         {
             for(int k=0;k<C;k++)
             temp[k]+=M[j][k];
             maxm=max(maxm,kadane(temp,C));
         }
     }
     return maxm;
    }
