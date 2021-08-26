#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float double
#define sz 100005
#define all(a) a.begin(), a.end()
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define debug cout << "here" << endl;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int, int>

int mpow(int a, int b, int m)
{
    if (b == 0) return 1;
    int x = mpow(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2) x = (x * a) % m;
    return x;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
     int mod =1000000007;
     int tc;
     cin >> tc;
     while(tc--){
        int n,k;
        cin >> n >> k;
        if(k == 0) cout << 1 << endl;
        if(k == 0) continue;

        vector<int> dp(k+1,0);

        for(int bit =0 ; bit < k ; bit++){
            if(bit == 0){
                int waysToWin = 0;
                if(n%2 == 0){
                    waysToWin = (mpow(2,n-1,mod))%mod;
                }else{
                    waysToWin = (1 + mpow(2,n-1,mod))%mod;
                }
                dp[bit] = waysToWin;
                continue;
            }

            int waysToWin = 0;

            if(n%2 == 0){
                waysToWin += mpow(2,((bit*n)),mod);
                int temp = (((mpow(2,n-1,mod)-1+mod)%mod)*dp[bit-1])%mod;
                waysToWin = (waysToWin + temp)%mod;
            }else{
                waysToWin += dp[bit-1];
                int temp = (mpow(2,n-1,mod)*dp[bit-1])%mod;
                waysToWin = (waysToWin + temp)%mod;
            }

            dp[bit] = waysToWin;
        }
        cout << dp[k-1] << endl;
     }

}