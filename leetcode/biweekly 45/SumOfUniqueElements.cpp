//incomplete
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
     int n = nums.size();
        int sum =0;
        int ar[101] ={0};
        for(int i =0;i<n;i++)
            ar[nums[i]]++;
        for(int i =1;i<101;i++)
            if(ar[i]==1) sum+= i;
        return sum ;
    }
};