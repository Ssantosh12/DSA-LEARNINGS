class Solution {
    public int coinChange(int[] coins, int amount) {
        // TODO: Explain the learning properly
        // using iterative dp
        //dp[i]=minimum number of coins needed to make upto ith amount of money
        //choices: at each step we can choose any element/coin from the array of coins
        int i,j;

        int[] dp=new int[amount+1];
        
        dp[0]=0;
        for(i=1;i<=amount;i++){
            // from all the choices we have , we choose which requires minimum coins
            dp[i]=10001; // we assume that ith amount requires infinite coins/not possible
            
            for(j=0;j<=coins.length-1;j++){
                if((i-coins[j])>=0)
                    dp[i]=Math.min(dp[i],1+dp[i-coins[j]]);
            }
        }

        if(dp[amount]>10000)
            dp[amount]=-1;
        return dp[amount];
    }
}
