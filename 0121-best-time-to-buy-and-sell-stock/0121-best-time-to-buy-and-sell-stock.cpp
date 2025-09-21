// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n= prices.size();
//         int buy; //= min(prices.begin(),prices.end());
//         buy= *min_element(prices.begin(),prices.end());
//         // int buy;
//         // int a;
//         // for(int i =0; i<n; i++){
//         //     for(int j=i+1; j<n; j++){
//         //         if(prices[i]<prices[j]) buy=prices[i];
//         //     }
//         //     a=i;
//         // }
//         int a;
//         for(int i =0; i<n; i++)
//             if(prices[i]== buy) a=i;
        
//          int sell; // = max(prices.begin()+a,prices.end());
//          sell = *max_element(prices.begin()+a,prices.end());
//         // int sell;
//         // for(int i=a+1; i<n; i++){
//         //     for(int j=i+1; j<n; j++){
//         //         if(prices[i]>prices[j]) sell=prices[i];
//         //     }
//         // }

//         if(a==n-1)  return 0;
//         if(buy>sell) return 0;
//         else return sell-buy;
//     }
// };

// we have to think of what should be the best buy in privous days 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = INT_MAX;
        int best = 0;
        for (int p : prices) {
            min_so_far = min(min_so_far, p);   // potential buy
            best = max(best, p - min_so_far);  // potential sell today
        }
        return best;
    }
};
