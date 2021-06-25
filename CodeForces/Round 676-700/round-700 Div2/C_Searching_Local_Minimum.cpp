//complete
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n;
int a[MAXN];
 
int query(int x){
	if (1 <= x && x <= n){
		printf("? %d\n", x);
		fflush(stdout);
		scanf("%d", &a[x]);
	}
}
int main()
{
	scanf("%d", &n);
	a[0] = a[n + 1] = n + 1;
	int low = 1, high = n;

	while (low < high){
		int m = (low + high) / 2;
		query(m);
		query(m + 1);
		if(a[m] < a[m+1])  high = m;
		else               low = m + 1;
	}

	printf("! %d\n", low);
	fflush(stdout);
	return 0;
}