#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


#define INT_MAX 1e4
#define loop for(int i = 0; i < n; i++)
#define lop(i,n) for (int i = 0; i < n; i++)
#define lp(i,k, n) for (int i = k; k < n? i < n: i > n; k < n? i += 1: i -= 1)
#define endl "\n"
typedef vector<int> vi;

int dp[4020][4020];
int sumArr[4020];
unsigned short n, k;

int knapsack(unsigned short j,int  a,vi &h)
{ 
    if((a >= k) and ( sumArr[j]-a>=k)) 
        return 0;
    if(j >= n)  return 1e4 ;
    else if (dp[j] [a] != -1) return dp[j][a];
    int  x = knapsack( j + 1, min( a, h[j] +sumArr[j] - a  ),  h);
    int  y = knapsack( j + 1, min( a + h[j], sumArr[j] - a ),  h);
    return dp[j][a] = min(1+x,1+y);
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

 int Testcase = 1;
 cin >> Testcase;

 while (Testcase--) {
    cin>>n>>k;
    vi h(n,0);
    loop cin>>h[i];
    
    sort(h.begin(),h.end(),greater<int>());
    lop(i,n+10) lop(j,k+10) dp[i][j]=-1;

    lp(i, 1, n+1) sumArr[i] = sumArr[i-1] + h[i-1];
    
    int ans = knapsack(0,0,h);
    if( ans >= 1e4-5000) cout<<-1<<endl;
    else cout<< knapsack(0,0,h)<<endl;
 };
 return 0;
}