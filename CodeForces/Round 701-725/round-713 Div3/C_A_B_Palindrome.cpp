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
    int a, b ;
    cin>>a>>b;
    string s ;
    cin>>s;
    int n = s.size();
    if(a%2 and b%2){
        cout<<-1<<endl;
        return ;
    }
    loop{
        if(s[i] != '?') {
            if(s[n-i-1] != '?' and s[n-i-1] != s[i]) {
                cout<<-1<<endl;
                return;
            }
            else s[n-i-1] = s[i];
        }
    }
    if(a%2 ==0 and b%2 ==0 ){
        int cnta =0 ,cntb=0;
        loop {
            if(s[i] =='0') cnta++;
            else if(s[i] == '1') cntb++;
        }
            if(cnta >a or cntb>b) {
                cout<<-1<<endl;
                return;
            }
            else {
                a  -= cnta;
                b -= cntb;
            }
        int i =0;
        while(a != 0){
            if( s[i] =='?'){
                s[i] ='0';s[n-i-1] ='0';
                a-=2;
            }
            i++;
        }
        while(b != 0){
            if(s[i] == '?'){
                s[i] = '1';s[n-i-1] ='1';
                b -=2;
            }
            i++;
        }
    }
    else if(a%2 or b%2){
        if(a%2) {
            if(s[n/2] != '?' and s[n/2] != '0') {
                cout<<-1<<endl;
                return;
            }
            s[n/2] = '0';
        }
        else {
            if(s[n/2] != '?' and s[n/2] != '1') {
                cout<<-1<<endl;
                return;
            }
            s[n/2] ='1';
        }
        int cnta =0 ,cntb=0;
        loop {
            if(s[i] =='0') cnta++;
            else if(s[i] == '1') cntb++;
        }
            if(cnta > a or cntb > b) {
                cout<<-1<<endl;
                return;
            }
            else {
                a  -= cnta;
                b -= cntb;
            }
            debug(cnta,cntb,a,b,s);
        int i =0;
        while(a != 0){
            if( s[i] =='?'){
                s[i] ='0';s[n-i-1] ='0';
                a-=2;
            }
            i++;
        }
        while(b != 0){
            if(s[i] == '?'){
                s[i] = '1';s[n-i-1] ='1';
                b -=2;
            }
          i++;
        }
    }
    cout<<s<<endl;

}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 

 int Testcase = 1;
 cin>>Testcase;   
 while (Testcase--)Solve();
 return 0;
}