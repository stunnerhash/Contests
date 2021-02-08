#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int maxAbsoluteSum(vector<int>& nums) {
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < nums.size(); i++) 
    { 
        max_ending_here = max_ending_here + nums[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    int min_so_far = INT_MAX, min_ending_here =0;
    for (int i = 0; i < nums.size(); i++) 
    { 
        min_ending_here = min_ending_here + nums[i]; 
        if (min_so_far > min_ending_here) 
            min_so_far = min_ending_here; 
  
        if (min_ending_here > 0) 
            min_ending_here = 0; 
    } 
    cout<< min_so_far<<" "<<max_so_far<<endl;
     return max( abs(min_so_far), max_so_far);
}
};