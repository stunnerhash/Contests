#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i=0, j=n-1;
        while(i<j){
            char temp;
            if(s[i] == s[j]) temp = s[i];
            else break;
            while(i<=j){
                if(s[i] == temp) i++;
                else break;
            }
            while(j>i) {
                if(s[j] == temp) j--;
                else break;
            }
        }
        int ans =j-i+1;
        return ans;
    }
};