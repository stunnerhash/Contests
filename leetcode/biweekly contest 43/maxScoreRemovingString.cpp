// incomplete
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string a="ab",b="ba";
        int ans =0;
        if(x < y) {
            swap(a[0],b[0]);
            swap(a[1],b[1]);
        }
        int teans=0;
        for(int i =0;i<s.size()-1;i++)
        {
            if(s[i]==a[0] and s[i+1] == a[1]){
                teans ++;
                cout<<s[i]<<s[i+1]<<endl;
                s.erase(i,i+1);
                i-=2;
            }
        }
        ans = teans * x;
        cout<< s <<endl;
//         while(s.find(a) != string::npos and s.find(b) != string::npos){
            
//             if(s.find(a) != string::npos)
//                 ans+=reduce(s,a);
            
//             else {
//                 for(int i =0;i<s.size()-1;i++){
//                     if(s[i] ==  b[0] and s[i+1] == b[1]){
//                         s.erase(i,i+1);
//                         break;
//                     }
//                 }
//                 ans++;
//             }
        // }
        return ans;
    }
};