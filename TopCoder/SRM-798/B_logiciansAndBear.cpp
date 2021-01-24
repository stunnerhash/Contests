#include<bits/stdc++.h>
using namespace std;

class LogiciansAndBeer
{
public:
    int bringBeer(string resp){
        int n = resp.size();
        bool wrong =0;
        int ans;
        if(resp[n-1] == '?') wrong =1;
        else for(int i =0;i<n;i++){
            if(i<n-1 && resp[i] == '+'){
                wrong =1;
                break;
            }

            if(resp[i] == '-'){
                ans=i;
                for(;i<n;i++) if(resp[i] != '-') wrong =1;
            }
        }
        if(wrong) return -1;
        else return ans;
    }
};