//unsolved;

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop for(int i = 0; i < n; i++) 
#define looop(i, n) for (int i = 0; i < n; i++) 
#define loopp(i, k, n) for (int i = k; k < n? i < n: i > n; k < n? i += 1: i -= 1) 
#define dbug(x) cout << #x << "=" << x << endl
#define debug(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define clr(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define trav(a) for (auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

void Solve()
{
    string s;
    cin>>s;
    int cnt =0;
    int n = s.size();
    int i=0;
    while(i<n-1){
        if(s[i] != s[i+1]) {
            i++;
            continue;
        }
        int tp_cnt=0;
        while(i<n && s[i] == s[i+1]) {
            tp_cnt;
            i++;
        }
        if(s[i] == s[i+1]) cnt++;
    }
    cout<< cnt<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 srand(chrono::high_resolution_clock::now().time_since_epoch().count());

 int Testcase = 1;
 cin >> Testcase;

 while (Testcase--) Solve();
 return 0;
}