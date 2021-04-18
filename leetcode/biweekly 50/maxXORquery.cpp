#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int  n = nums.size(); 
        vector<unsigned int> xr(n);
        vector<int> ans ( n);
        xr[0] = nums[0];
        for(int i =1;i<n;i++) xr[i] = nums[i]^xr[n-1];
        for(int i =0 ;i<n;i++){
            int temp = ((1 << maximumBit) - 1) ^ xr[i];
            ans[n-i-1] = temp;
        }
        return ans;
    }
};
int main(){
        int nbit = floor(log2(9))+1;
        int temp = ((1 << nbit) - 1) ^ 9;    
        cout<<nbit<<" "<<(1<<nbit)-1<<endl;
        cout<<temp<<endl;
}