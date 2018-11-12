Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.

 

Example 1:

Input: A = [1], K = 1
Output: 1
Example 2:

Input: A = [1,2], K = 4
Output: -1
Example 3:

Input: A = [2,-1,2], K = 3
Output: 3
 

Note:

1 <= A.length <= 50000
-10 ^ 5 <= A[i] <= 10 ^ 5
1 <= K <= 10 ^ 9


Difficulty: Hard

Which is quite similar to No.739_Daily_Temperatures, use deque to eliminate useless info.


It's not quite good to use two pointer method. E.g. A = [-28,81,-20,28,-29], K = 89, output 3 but not -1; A = [84,-37,32,40,95], K = 167,output 3 but not 5; might suffer a lot.



class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int N=A.size();
        int res=N+1;
        vector<int>B(N+1,0);
        for(int i=0;i<N;i++){
            B[i+1]=B[i]+A[i];
        }
        deque<int> dq;
        for(int i=0;i<=N;i++){
            while(dq.size()>0&&B[i]-B[dq.front()]>=K){
                res=min(res,i-dq.front());
                dq.pop_front();
            }
            while(dq.size()>0&&B[i]<=B[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        return res<N+1?res:-1;
    }
};