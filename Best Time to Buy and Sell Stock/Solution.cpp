class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //f(0) = 0,min = p[0]
        //f(n) = max(f(n-1),p[n]-min)
        int maxP = 0;
        if(prices.empty())return maxP;
        int min = prices[0];
        int size = prices.size();
        for(int i=1;i<size;i++)
        {
            if(prices[i]>min)
            {
                maxP = (maxP>prices[i]-min ? maxP:prices[i]-min);
                min = (min<prices[i] ? min : prices[i]);
            }
            else
            {
                min = (min<prices[i] ? min : prices[i]);
            }
        }
        return maxP;
        
    }
};