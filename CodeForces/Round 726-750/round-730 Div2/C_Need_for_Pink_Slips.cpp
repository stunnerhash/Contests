#include <bits/stdc++.h>
using namespace std;
#define ld long double

const ld eps = 1e-9;
const ld scale = 1e+6;

ld expRaces(int c,int m,int p,int v)
{
    ld ans = p/scale;
    if(c>0) {
        if(c>v) {
            if(m>0) ans += (c/scale)*(1+expRaces(c-v,m+v/2,p+v/2,v));
            else ans += (c/scale)*(1+expRaces(c-v,0,p+v,v));
        }
        else {
            if(m>0) ans += (c/scale)*(1+expRaces(0,m+c/2,p+c/2,v));
            else ans += (c/scale)*(1+expRaces(0,0,p+c,v));
        }
    }
    if(m>0) {
        if(m>v) {
            if(c>0) ans += (m/scale)*(1+expRaces(c+v/2,m-v,p+v/2,v));
            else ans += (m/scale)*(1+expRaces(0,m-v,p+v,v));
        }
        else {
            if(c>0) ans += (m/scale)*(1+expRaces(c+m/2,0,p+m/2,v));
            else ans += (m/scale)*(1+expRaces(0,0,p+m,v));
        }
    }
    return ans;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        ld cd,md,pd,vd;
        cin >> cd >> md >> pd >> vd;

        int c = round(cd*scale);
        int m = round(md*scale);
        int p = round(pd*scale);
        int v = round(vd*scale);

        ld ans = expRaces(c,m,p,v);

        cout << setprecision(12) << fixed << ans << '\n';
    }
}