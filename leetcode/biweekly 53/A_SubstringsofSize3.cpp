#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop for(int i = 0; i < n; i++) 
#define lop(i, n) for (int i = 0; i < n; i++) 
#define lp(i, k, n) for (int i = k; k < n? i < n: i > n; k < n? i += 1: i -= 1) 
#define dbg(x) cout << #x << "=" << x << endl
#define dbug(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
//#define read(type) readInt<type>()
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
    int countGoodSubstrings(string s) {
        int n = s.size();
        int ans =0;
        for(int i =0;i<n-2;i++){
            string str = s.substr(i,3);
            if(str[0]!= str[1] and str[1] != str[2] and str[2] != str[0]) ans ++;
        }
        return ans;
    }
};