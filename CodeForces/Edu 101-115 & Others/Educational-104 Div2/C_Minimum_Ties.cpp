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

void Solve()
{
    int n ;
    cin>>n;
    if ( n %2) {
        for(int i =0;i<n-1;i++){
            int j =0,cnt =0;
            for( j =i;j<n-1;j++){
                cout<<" 1 ";
                cnt++;
                if(cnt == n/2)  break;
            }
            for( ;j<n-2;j++){
                cout<<"-1 ";
            }
            cout<< endl;
        }
        return;
    }

    for(int i =0;i<n-1;i++){
            int j =i;
            if(i%2 == 0){
                 cout<<" 0 ";
                j++;
            }
            for(int cnt =0;j<n-1;j++){
                cout<<" 1 ";
                cnt++;
                if(cnt == (n/2) -1)  break;
            }
            for( ;j<n-2;j++){
                cout<<"-1 ";
            }
            cout<<endl;
    }
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 

 int Testcase = 1;
 cin>>Testcase;   
 while (Testcase--)Solve();
 return 0;
}