class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0,tmp;
        int n = prices.size();
        int buy = prices[0],sell=prices[n-1];
        vector<int> maxi(n),mini(n);
        mini[0]=buy;maxi[n-1]=sell;
        for(int i=1;i<n;i++){
            mini[i]=min(prices[i],mini[i-1]);
        }
        for(int i=n-2;i>0;i--){
            maxi[i]=max(prices[i],mini[i+1]);
        }
        for(int i=0;i<n-1;i++){
            tmp = maxi[i+1]-mini[i];
            profit = max(tmp,profit);
        }
        return profit;
        
    }
};
