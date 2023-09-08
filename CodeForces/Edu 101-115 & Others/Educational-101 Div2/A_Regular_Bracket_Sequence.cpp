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
    bool flag =1;
    int cnt=0;
    int extra =0;
    for(int i =0;i<s.size(); i++){
        if(s[i] == '(') cnt++;
        else if(s[i] == ')') cnt--;
        else  extra ++;
        if(cnt < 0) {
            if(extra <=0) flag =0;
            else{
                extra--;
                cnt++;
            }
        }
    }
    for(int i=s.size()-1;i>=0;i--)
    {
    if(s[i] == '?') continue;
    else if(s[i] == ')') break;
    else if(s[i] == '(') {
        flag=0;
        break;
    }
    }
        if((cnt-extra)%2 == 0 && flag) cout<< "YES\n";
    else cout<<"NO\n";
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 

 int Testcase = 1;
 cin >> Testcase;

 while (Testcase--) Solve();
 return 0;
}