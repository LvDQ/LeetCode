Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000




Difficulty: Medium(Two sigma) & LYB 

Solution: https://leetcode.com/problems/maximum-sum-circular-subarray/solution/

Method: Kadane method for non-circle array.

then use sum(A) + max_kadane(-1*A) --->len-1




class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int Sum=0;
        int n=A.size();
        for(auto a:A)Sum+=a;
        int res1=helper(A,0,n,1);
        int res2=helper(A,0,n-1,-1)+Sum;
        int res3=helper(A,1,n,-1)+Sum;
        return max(res1,max(res2,res3));
        
    }
    
    int helper(vector<int>& A,int left, int right, int sign){  // Kadane's method
        int count=0;
        int res=INT_MIN;
        for(int i=left;i<right;i++){
            count+=sign*A[i];
            res=max(res,count);
            if(count<0)count=0;
        }
        return res;
    }
    
};
