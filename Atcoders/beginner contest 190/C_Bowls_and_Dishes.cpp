#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> cond(M);
    for(auto& x: cond) cin >> x.F>> x.S;
    int K;
    cin >> K;
    vector<pair<int, int>> choice(K);
    for(auto& y: choice) cin >> y.F >> y.S;
    
    int ans = 0;
    //run while bit < 2^k;
    for(int bit = 0; bit < 1 << K; bit++){
        vector<bool> ball(N);
        for(int i = 0; i < K; i++){
            const int C = choice[i].F;
            const int D = choice[i].S;
            ball[bit & 1 << i ? C : D] = 1;
        }
        //count 
        int cnt = 0;
        for(auto x: cond) if(ball[x.F] && ball[x.S]) cnt++;
        ans = max(ans,cnt);
    }
    cout << ans << endl;
}
