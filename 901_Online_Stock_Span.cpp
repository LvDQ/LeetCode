/*Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].


Example 1:

Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
Output: [null,1,1,1,2,1,4,6]
Explanation: 
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.

*/


//Related problems: 739_Daily_Temperature

// My first AC code
class StockSpanner {
public:
    StockSpanner() {
        prices.clear();
        res.clear();
    }
    
    int next(int price) {
        int idx=prices.size()-1;
        // cout<<idx<<endl;
        for(;idx>=0;){
            if(price>=prices[idx]){
                idx-=res[idx];
                // cout<<idx<<endl;
            }
            else
                break;
        }
        
        
        // cout<<prices.size()<<" "<<idx<<endl;
        res.push_back(prices.size()-idx);
        // res=prices.size()-res;
        prices.push_back(price);
        return res.back();
    }
    
private:
    vector<int> res;
    vector<int> prices;
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */


//More elegant way:https://leetcode.com/problems/online-stock-span/discuss/168311/C++JavaPython-O(1)

/*Push every pair of <price, result> to a stack.
Pop lower price from the stack and accumulate the count.

One price will be pushed once and popped once.
So 2*N times stack operations and N times calls.
I'll say time complexity is O(1)
*/
    stack<pair<int, int>> s;
    int next(int price) {
        int res = 1;
        while (!s.empty() && s.top().first <= price) {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }