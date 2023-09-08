//incomplte
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

void Solve()
{
   int h , w;
   cin>>h>>w;
   vector<vector<char>> grid(h,vector<char>(w));
   vpi ar(h);

   lop(i,h) lop(j, w) cin>> grid[i][j] ;
	for(int i =0;i<h;i++){
	   int x= -1, y =-1;
    	for(int j=0; j<w;j++)
    	    if(grid[i][j] == '#'){
    	        x = j ;
    	        break;
    	    }
    	for(int j=0;j<w;j++)
    	    if(grid[i][j] == '#') y = j;
		ar[i].first =x;
		ar[i].second = y;
	}
    int ans =4;
	int x = ar[0].first, y = ar[0].second;
	for(int i =0;i<h;i++){
		if(ar[i].first == -1){
			x=-1;y=-1;
			continue;
		}
		if(x==-1 && y ==-1 ){
			
		}
		int nx=x , ny =y;
	}
//    for(;i<h;i++) {
//        bool flag =1;
//        int nx,ny;
       
//         for(j=0; j<w;j++)
//             if(grid[i][j] == '#'){
//                 nx = j;
//                 flag =0;
//                 break;
//         }
        
//         for(j=0;j<w;j++)
//             if(grid[i][j] == '#') ny = j; 
        
//         if(flag) break;
//         if(nx != x){
//             x=nx;
//             ans+=2;
//         }
//         if(ny != y){
//             y = ny;
//             ans +=2;
//         }
//     }
//     cout<< ans<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 

 int Testcase = 1;

 while (Testcase--)Solve();
 return 0;
}