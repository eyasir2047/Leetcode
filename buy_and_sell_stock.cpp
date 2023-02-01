class Solution {
    public int maxProfit(int[] prices) {
       int n=prices.length;
       
       int mini=prices[0];
       int max_profit=0;

       for(int i=1;i<n;i++){
           mini=Math.min(mini,prices[i]);
           max_profit=Math.max(max_profit,prices[i]-mini);
       }

       return max_profit;

        
    }
}