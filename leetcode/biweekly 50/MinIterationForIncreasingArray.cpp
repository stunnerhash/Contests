// https://leetcode.com/contest/biweekly-contest-50/problems/minimum-operations-to-make-the-array-increasing/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size ();
        int curr = nums[0];
        int next =0;
        int ans = 0 ;
        for (int i = 1; i < n; i++){
            next = nums[i];
            if(curr+1> nums[i] ) {
                ans += curr+1-nums[i];
                nums[i] = curr+1;
            }
            curr = nums[i];
        }
    }
};