#include <bits/stdc++.h>
using namespace std;
#define loop for(int i = 0; i < n; i++) 
#define read(type) readInt<type>()
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
int main() 
{ 
    int Test=1;
    cin>>Test;
    while(Test--){
	    long long  n ; cin>>n;
        vector<long long> a(n),b(n);
        loop cin>>a[i]>>b[i];
        sortall(a);sortall(b);  
        cout<<(a[n/2]-a[(n-1)/2]+1)*(b[n/2]-b[(n-1)/2]+1)<<endl;
    }
}