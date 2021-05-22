#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string sortSentence(string s) {
        int n = s.size();
        vector<pair<int , string>> v;
        int prev = 0;
        for(int i =0;i<n;i++){
            if(s[i] == ' ') {
                
                string str =  s.substr(prev,i-prev);
                prev = i+1;
                int tn = str.size();
                int num = str[tn-1] - 48;
                v.push_back(make_pair(num, str.substr(0,tn-1)));
            }
            else if ( i == n-1) {
                string str = s.substr(prev,i-prev+1);
                int tn = str.size();
                int num = str[tn-1]-48;
                v.push_back(make_pair(num,str.substr(0,tn-1)));
            }

        }
        
        sort(v.begin(),v.end());
        string init;
        for(int i =0;i<v.size();i++){
            init.append(v[i].second);
            if(i != v.size()-1) init.append(" ");
        }
        return init;
    }
};