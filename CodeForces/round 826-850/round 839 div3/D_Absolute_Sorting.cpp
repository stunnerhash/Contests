#include <bits/stdc++.h>
using namespace std;

#define loop     for(int i =0;i<n;i++)
#define lop(i,n) for(int i =0;i<n;i++)

typedef vector<int> vi;

int main()
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n; vi a(n); loop cin >> a[i];
        int mn = 0, mx = 1e9;
        lop(i,n-1){
            if(a[i] < a[i+1]) mx = min(mx,(a[i]+a[i+1])/2);
            if(a[i] > a[i+1]) mn = max(mn,(a[i]+a[i+1]+1)/2);
        }
        cout<<(mn <= mx? mn:-1)<<endl;
    }
    return 0;
}