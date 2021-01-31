#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     
    int getSum(int n){
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }
    int countBalls(int low, int high) {
        int n = high - low +1;
        int ar[n];
        int temp = low;
        int sum = getSum(temp);

        while(temp % 10){
            ar[sum]++;
            temp++;
            sum++;
        }
        sum = getSum(temp)-1;   
        while(temp<(high/10)*10){
            if(temp%10) {
                sum=getSum(temp);
                ar[sum]++;
                continue;
            }
            sum++;
            ar[sum]++;
        }

    }
};