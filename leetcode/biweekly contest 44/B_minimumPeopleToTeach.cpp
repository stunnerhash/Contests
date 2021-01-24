//incomplete

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& lang, vector<vector<int>>& fri)
    {
        int m = lang.size();
        int ans=0;
        for(int it=0 ;it < fri.size();it++){
            bool flag =0;
            int a= fri[it][0] - 1;
            int b = fri[it][1] - 1;
            
            for(int i = 0 ; i < lang[a].size(); ++i) 
            for (int j = 0 ; j < lang[b].size(); ++j)
                if(lang[a][i]==lang[b][j]) 
                    flag =true;      
            if(flag == 0) ans++;
        }
        cout<<endl;
        return ans;
    }
};