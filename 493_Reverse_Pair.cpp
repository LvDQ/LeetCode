493. Reverse Pairs

Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer

Difficulty: Hard


Method: https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22

Partition divide and conqure, merge sort.   BIT,BST based solution(?);

Similar questions:(Both hard) 315. Count of Smaller Numbers After Self;  327. Count of Range Sum



class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        return helper(nums,left,right);
    }
    
    int helper(vector<int>& nums,int left,int right){
        if(left>=right)return 0;
        int mid=(left+right)/2;
        int res=helper(nums,left,mid)+helper(nums,mid+1,right);
        sort(nums.begin()+mid+1,nums.begin()+right+1);
        for(int i=left;i<=mid;i++){
            // cout<<nums[3]<<" "<<nums[4]<<" ";
            int target = nums[i] > 0 ? (nums[i] - 1) / 2 : nums[i] / 2 - 1;
            res+=upper_bound(nums.begin()+mid+1,nums.begin()+right+1,target)-nums.begin()-mid-1;
            // cout<<left<<" "<<right<<" "<<res<<" nums[i]: "<<nums[i]<<" "<<mid+1<<endl;
        }
        return res;
    }
};