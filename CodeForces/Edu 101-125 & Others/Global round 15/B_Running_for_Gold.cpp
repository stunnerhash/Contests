#include <stdio.h>

int n, a[50005][8];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 5; j++)
				scanf("%d", &a[i][j]);
		int d = 1, c;
		for (int i = 2; i <= n; i++)
		{
			c = 0;
			for (int j = 1; j <= 5; j++)
				c += (a[i][j] < a[d][j]);
			if (c >= 3)
				d = i;
		}
		for (int i = 1; i <= n; i++)
		{
			c = 0;
			for (int j = 1; j <= 5; j++)
				c += (a[i][j] < a[d][j]);
			if (c >= 3)
			{
				d = -1;
				break;
			}
		}
		printf("%d\n", d);
	}
	return 0;
}