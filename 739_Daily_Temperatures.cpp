/*Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/


//related problems: 901. Online Stock Span

// We only need to merge the lower temperatures to a higher temperatures with weight of dates
// if one is small than temps.top(), then must be the answer

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        for(int i=temperatures.size()-1;i>=0;i--){ //move backwards
            int date=1;
            while(!temps.empty()&&temperatures[i]>=temps.top()){ //if temperatures[i]>=temps.top(), then we don't need to log temps.top() anymore
                date+=dates.top();
                temps.pop();
                dates.pop();
            }
            temps.push(temperatures[i]);
            if(dates.empty())date=0; // when stack is empty, no temperature higher than today in the future
            dates.push(date);
            temperatures[i]=date;
        }
        return temperatures;
    }
    
private:
    stack<int>dates;
    stack<int>temps;
};