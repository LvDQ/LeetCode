/*Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

//Difficulty: medium

//My virtural contest method:
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.empty())return true;
        int m=s1.size(),n=s2.size();
        if(m>n)return false;
        unordered_map<char,int> match;
        for(auto c:s1){
            match[c]++;
        }
        for(int i=0;i<n-m+1;i++){
            string tmp=s2.substr(i,m);
            // cout<<tmp<<endl;
            if(isvalid(match,tmp))return true;
        }
        return false;
    }
    
    bool isvalid(unordered_map<char,int> match,string tmp){
        for(auto c:tmp){
            match[c]--;
            if(match[c]<0)return false;
        }
        for(auto m: match){
            if(m.second>0)return false;
        }
        return true;
    }
};


//basically the method is to use s2 subarray to match s1 characters

//so we can easily transform above to a sliding window way:

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        if(s1.size()>s2.size())return false;
        vector<int> hashmap1(26,0);
        vector<int> hashmap2(26,0);
        for(auto c:s1){
            hashmap1[c-'a']++;
        }
        int left=0;
        for(int i=0;i<s2.size();i++){
            hashmap2[s2[i]-'a']++;
            if(i-left+1==n){
                if(hashmap1==hashmap2)
                    return true;
                hashmap2[s2[left]-'a']--;
                left++;
            }
        }
        return false;
    }
};
