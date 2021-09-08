#include <iostream>
using namespace std;
int n, m1, m2, a, b, f1[1010], f2[1010], cnt, ans;

int find1(int x) {
	if (x == f1[x]) return x;
	else return f1[x] = find1(f1[x]);
}

int find2(int x) {
	if (x == f2[x]) return x;
	else return f2[x] = find2(f2[x]);
}

struct ffff
{
	int u, v;
} oo[1010];

int main()
{
	cin >> n >> m1 >> m2;
	for (int i = 1; i <= n; i++)
		f1[i] = i, f2[i] = i;

	for (int i = 1; i <= m1; i++)
		cin >> a >> b, f1[find1(a)] = find1(b);

	for (int i = 1; i <= m2; i++)
		cin >> a >> b, f2[find2(a)] = find2(b);

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (i == j) continue;

			if (f1[find1(i)] != f1[find1(j)] && f2[find2(i)] != f2[find2(j)]) {
				ans++;
				f1[find1(i)] = find1(j);
				f2[find2(i)] = find2(j);
				oo[++cnt].u = i;
				oo[cnt].v = j;
			}
		}
	}
	cout << ans << endl;
	if (ans != 0)
		for (int i = 1; i <= cnt; i++)
			cout << oo[i].u << " " << oo[i].v << endl;
	return 0;
}