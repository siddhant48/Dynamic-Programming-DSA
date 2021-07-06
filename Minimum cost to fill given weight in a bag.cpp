// Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ 
// kg packet of oranges, the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1

// Note:
// 1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
// 2. It may be assumed that there is infinite supply of all available packet types.

int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        int dp[W+1];
        dp[0]=0;
        for(int i=1;i<=W;i++)
        dp[i]=INT_MAX;
        for(int i=1;i<=W;i++)
        {
            for(int j=0;j<N;j++)
            {
                if((j+1)<=i && cost[j]!=-1 && dp[i-(j+1)]!=INT_MAX)
                {
                    dp[i]=min(dp[i],dp[i-(j+1)]+cost[j]);
                }
            }
        }
        if(dp[W]==INT_MAX) return -1;
        return dp[W];
	} 
