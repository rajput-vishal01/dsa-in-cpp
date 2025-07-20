// Leetcode 121. Best Time to Buy and Sell Stock
class Solution {
public:

    int maxProfitRE(vector<int>& prices,int index ,int &min_price,int &max_profit){
      if(index>=prices.size()){
        return max_profit; 
      }

      int current_profit=prices[index]-min_price;
      max_profit=max(max_profit, current_profit);

      min_price=min(min_price,prices[index]);

     return maxProfitRE(prices,index+1,min_price,max_profit);

    }

    int maxProfitIterative(vector<int>& prices){
      int min_price=prices[0];
      int max_profit=0;
        
        for(int i=1;i<prices.size();i++){
            // Update minimum price seen so far
            min_price=min(min_price,prices[i]);
            
            // Calculate profit if we sell today
            int current_profit=prices[i]-min_price;
            
            // Update maximum profit
            max_profit=max(max_profit, current_profit);
        }
        
        return max_profit;
    }

    int maxProfit(vector<int>& prices) {
    //int ans = maxProfitIterative(prices); //recommended

    int min_price = prices[0];  // Initialize with first price
    int max_profit = 0;

    int ans = maxProfitRE(prices,1,min_price,max_profit);
    return ans;
        
    }
};