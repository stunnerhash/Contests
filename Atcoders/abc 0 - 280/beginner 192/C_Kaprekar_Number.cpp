#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop for(int i = 0; i < n; i++) 
#define lop(i, n) for (int i = 0; i < n; i++) 
#define lp(i, k, n) for (int i = k; k < n? i < n: i > n; k < n? i += 1: i -= 1) 
#define dbg(x) cout << #x << "=" << x << endl
#define dbug(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define read(type) readInt<type>()
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
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

unsigned ll smallest(int num) { 
    int freq[10] = {0}; 
    while (num) { 
        int d = num % 10; 
        freq[d]++;
        num = num / 10; 
    } 
  
    unsigned ll result = 0; 
    for (int i = 1 ; i <= 9 ; i++) { 
        if (freq[i]) { 
            result = i; 
            freq[i]--; 
            break; 
        } 
    } 
    for (int i = 1 ; i <= 9 ; i++) 
        while (freq[i]--) 
            result = result * 10 + i; 
    return result; 
} 
unsigned ll greatest(int num) { 
    int count[10] = {0}; 
      string str = to_string(num); 
      for (int i=0; i<str.length(); i++) 
        count[str[i]-'0']++; 
      int result = 0, multiplier = 1; 
    for (int i = 0; i <= 9; i++) { 
        while (count[i] > 0) { 
            result = result + (i * multiplier); 
            count[i]--; 
            multiplier = multiplier * 10; 
        } 
    } 
     return result; 
} 
void Solve()
{
    int n ,k;
    cin>>n>>k;
    int temp =0;
    for(int i =0;i<k;i++){
        debug(n,greatest(n),smallest(n));
        n = greatest(n)-smallest(n);
    }
    cout<<n<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 

 int Testcase = 1; 
 while (Testcase--)Solve();
 return 0;
}