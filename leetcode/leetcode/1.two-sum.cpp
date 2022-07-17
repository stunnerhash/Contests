#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
    vector<int> vi;
    map <int,int> s;
public:
    vector<int> twoSum(vector<int>& nums, int t) { 
        for(int i = 0 ;i < nums.size(); i++)
            if(s[ t-nums[i] ] > 0){
                vi.insert ( vi.end(),{ s [ t- nums[i] ] - 1,i});
                return vi;
            }
            else s[nums[i]] = i+1;
        return vi;
		//helper
    }
};
// @lc code=end

