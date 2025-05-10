class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof=0;
        int minprice=prices[0];
        for(int i=0;i<prices.size();i++){
            int prof=prices[i]-minprice;
            if(prof>maxprof){maxprof=prof;}
            if(prices[i]<minprice){minprice=prices[i];}   
        }
        return maxprof;
    }
};