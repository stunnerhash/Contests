#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop for(int i = 0; i < n; i++) 
#define lop(i, n) for (int i = 0; i < n; i++) 
#define lp(i, k, n) for (int i = k; k < n? i < n: i > n; k < n? i += 1: i -= 1) 
#define dbg(x) cout << #x << "=" << x << endl
#define dbug(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define clr(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define trav(a) for (auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
#define INF (int)1e9
#define EPS 1e-9
#define mod 1000000007
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& b) {
        int n = b.size();
        int m = b[0].size();
        loop {
            int prev=0;
            int j =0;
            int s=0;
            int e=0;
            while(j<m){
                if(j == m-1 && b[i][j] != '*') {
                    if(b[i][j] == '#')s++;
                    else if (b[i][j] == '.')e++;
                    
                    while(e--){
                        b[i][prev] = '.';
                        prev++;
                    }
                    while(s--){
                        b[i][prev] = '#';
                        prev++;
                    }

                    break;
                }
                if(b[i][j] =='*'){
                    while(e--){
                        b[i][prev] = '.';
                        prev++;
                    }
                    while(s--){
                        b[i][prev] = '#';
                        prev++;
                    }
                }
                else if(b[i][j] == '#')s++;
                else if (b[i][j] == '.')e++;
            }
        }
    }
};