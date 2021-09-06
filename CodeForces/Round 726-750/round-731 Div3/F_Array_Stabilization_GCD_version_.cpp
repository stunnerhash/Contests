#include <bits/stdc++.h>
using namespace std;

#define loop for (int i = 0; i < n; i++)
#define pb push_back
const int MAX_A = 1000'000;
vector<int> sieve(MAX_A + 1);
vector<int> prime;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    loop cin >> a[i];

    int common = 0;
    vector<set<int>> facts(n);
	loop common = gcd(common, a[i]);
	
    loop {
        int t = a[i] / common;
        while (t != 1) {
            facts[i].insert(sieve[t]);
            t /= sieve[t];
        }
    }

    int answer = 0;
    loop {
        for (int p : facts[i]) {
            int l = (i + n - 1) % n, r = i;
            int cnt = 0;
            while (facts[l].count(p) > 0) {
                facts[l].erase(p);
                l--; cnt++;
                if (l < 0) 
                    l = n - 1;
            }
            while (facts[r].count(p) > 0) {
                if (r != i) 
                    facts[r].erase(p);
                ++r %= n; cnt++;
            }
            answer = max(answer, cnt);
        }
        facts[i].clear();
    }
	cout<<answer<<endl;
}

int main() {

    sieve[1] = 1;
    for (int i = 2; i <= MAX_A; i++) {
        if (sieve[i] == 0) {
            sieve[i] = i;
            prime.pb(i);
        }
        for (int j = 0; j < prime.size() && prime[j] <= sieve[i] && i * prime[j] <= MAX_A; j++) 
            sieve[i * prime[j]] = prime[j];
    }

    int t; cin >> t;
	while(t--)  solve();
}
