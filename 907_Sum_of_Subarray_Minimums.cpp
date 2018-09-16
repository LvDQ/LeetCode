Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000


difficulty: medium


attempt1: add all subarray minimum all, Time Complexity: O(n^2)

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        long res=0;
        int mod = 1e9+7;
        for(int i=0;i<A.size();i++){
            int mini=50000;
            for(int j=i;j<A.size();j++){
                mini=min(mini,A[j]);
                res+=mini;
                // cout<<mini<<" "<<res<<endl;
                res%=mod;
            }
        }
        return (int)res;
    }
};

Result: TLE


Attempt2: find A[i] and its times, then multiply them

Method: if A[0..j]>=A[i], then on the left side, we have i-j possibilities with the situation A[i] is the minimum value in A[j+1..i]

when it comes to A[i]<A[k..n] on the right side, we have k-i possibilities with the situation A[i] is the minimum value in A[i..k-1]

so there are (i-j)*(k-i) times that A[i] is the minimum value

so we can get the answer 

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        long res=0;
        int mod = 1e9+7;
        int n=A.size();

        for(int i=0;i<n;i++){
            int left=1,right=1;
            for(int j=i-1;j>=0;j--){
                if(A[j]>=A[i])left++;
                else
                    break;
            }
            for(int k=i+1;k<n;k++){
                if(A[k]>A[i])right++;
                else 
                    break;
            }
            res+=left*right*A[i];

            res%=mod;
        }
        return (int)res;
    }
};


Result: AC, but 1544ms, which seems not so good, Complexity: Worst Case near O(n^2)



Attempt3: Better way to calculate left, right, then get the times by using stack

class Solution {
public:
    int sumSubarrayMins(vector<int> A) {
        int res = 0, n = A.size(), mod = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<pair<int, int>> s1,s2;
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!s1.empty() && s1.top().first > A[i]) {
                count += s1.top().second;
                s1.pop();
            }
            s1.push({A[i], count});
            left[i] = count;
        }
        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!s2.empty() && s2.top().first >= A[i]) {
                count += s2.top().second;
                s2.pop();
            }
            s2.push({A[i], count});
            right[i] = count;
        }
        for (int i = 0; i < n; ++i)
            res = (res + A[i] * left[i] * right[i]) % mod;
        return res;
    }
};


https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/C++JavaPython-Stack-Solution
Intuition:

res = sum(A[i] * f(i))
where f(i) is the number of subarrays,
in which A[i] is the minimum.

To get f(i), we need to find out:
left[i], the length of strict bigger numbers on the left of A[i],
right[i], the length of bigger numbers on the right of A[i].

Then,
left[i] + 1 equals to
the number of subarray ending with A[i],
and A[i] is single minimum.

right[i] + 1 equals to
the number of subarray starting with A[i],
and A[i] is the first minimum.

Then f(i) = (left[i] + 1) * (right[i] + 1)

For [3,1,2,4] as example:
left + 1 = [1,2,1,1]
right + 1 = [1,3,2,1]
f = [1,6,2,1]
res = 3 * 1 + 1 * 6 + 2 * 2 + 4 * 1 = 17

Explanation:
To calculate left[i] and right[i],
we use two increasing stacks.

It will be easy if you can refer to this problem and my post:
901. Online Stock Span
I copy some of my codes from this solution.

Here I record (A[i], count) in the stack.
We can also only record index.

More:
For some more similar problem, I suggest
828. Unique Letter String
891. Sum of Subsequence Widths

Complexity:
All elements will be pushed twice and popped at most twice
O(N) time, O(N) space