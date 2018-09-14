/*Virtual User Accepted: 130
Virtual User Tried: 175
Virtual Total Accepted: 130
Virtual Total Submissions: 175
Difficulty: Medium
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

//difficulty: medium


//my brute force method:
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            long tmp=0;
            for(int j=i;j>=0;j--){
                tmp+=nums[j];
                if(tmp==k){
                    res++;
                }
            }
        }
        return res;
    }
};

// more elegant way:https://leetcode.com/problems/subarray-sum-equals-k/solution/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cum=0; // cumulated sum
        map<int,int> rec; // prefix sum recorder
        int cnt = 0; // number of found subarray
        rec[0]++; // to take into account those subarrays that begin with index 0
        for(int i=0;i<nums.size();i++){
            cum += nums[i];
            cnt += rec[cum-k];
            rec[cum]++;
        }
        return cnt;
    }
};