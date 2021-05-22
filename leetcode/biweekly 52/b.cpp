#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        vector<int> arr(3);
        int i =0;
        while(1){
            i++;
            if(i>memory1 && i > memory2) {
                   arr[0]=  i ;
                break;
            }
            if(memory2>memory1) memory2 -= i;
            else memory1 -= i;
        }
        arr[1] = memory1;
        arr[2] = memory2;
        return arr;
    }
};