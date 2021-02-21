#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& gp, vector<int>& nums) {
        int n = nums.size();
        int gps= gp.size();
        vector<pair<int,int>> vpi;
        int flag = 1;

        for(int i = 0; i < gps;i++){
            int m = gp[i].size();
            flag *= idx ( nums , gp [i] , n , m , vpi) ;
        }
        int vpn = vpi.size();
        for(int i =1;i<vpn;i++){
            if(vpi[i-1].second >= vpi[i].first) flag =0;
        }
        return flag;
    }
    bool idx(vector<int>A, vector<int> B, int n, int m,vector<pair<int,int>>& vpi) { 
        int i = 0, j = 0,start =-1;
        bool flag = 0;
        while (i < n && j < m) { 
            if (A[i] == B[j]) { 
                if(start == -1) start = i;
                i++; 
                j++; 
                if (j == m) {
                    vpi.push_back(make_pair(start,start+j-1));
                    
                    flag = true;
                    break;
                }
            } 
            else { 
                i = i - j + 1; 
                j = 0; 
                start =-1;
            }
        }
        return flag; 
    } 
};