//Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]==1) ans=1;
        }
        for(int i=0;i<m;i++)
        {
            if(mat[0][i]==1) ans=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j]==1){
                       int temp=min(mat[i][j-1],min(mat[i-1][j],mat[i-1][j-1]))+1;
                ans=max(ans,temp);
                mat[i][j]=temp;
                }
              
            }
        }
        return ans;
    }
