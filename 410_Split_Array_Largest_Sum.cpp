Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.


Difficulty: Hard

Method: Greedy + Binary Search

showed in Xiaomi's OA



class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int lo=0,hi=INT_MAX;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(isvalid(nums,m,mid)){
                hi=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
    
    bool isvalid(vector<int>&nums, int m,int M){
        int count=0;
        int n=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>M)return false;
            if(count+nums[i]>M){
                n++;
                if(n>m)return false;
                count=nums[i];
            }
            else{
                count+=nums[i];
            }
        }
        return true;
    }
    
};