#include <bits/stdc++.h>
using namespace std;

#define loop           	for (int i = 0; i < n; i++)
#define lop(i, n)      	for (int i = 0; i < n; i++)
#define lp(i, k, n)    	for (int i=k;k < n?i < n: i>n;k < n? i+=1: i-=1)
#define trav(a) 		for (auto it = a.begin();  it != a.end();  it++)
#define dbg(x)         	{cout<<#x<<"="<<x<<endl;cerr<<#x<<"="<<x<<endl;}
#define yes(x)      	cout<<(x?"YES\n":"NO\n")
#define no             	{cout<< "NO\n"; return;}
#define clear(x)       	memset (x, 0, sizeof(x))
#define all(x)         	x.begin(), x.end()
#define sortall(x)    	sort(all(x))
#define ll             	long long
#define pb             	push_back
#define mp             	make_pair
#define ss             	second
#define ff             	first
#define endl           	"\n"
typedef pair<int, int> 	pi;
typedef pair<ll, ll>   	pl;
typedef vector<int>    	vi;
typedef vector<ll>     	vl;
typedef vector<pi>     	vpi;
typedef vector<vi>     	vvi;
const ll mod  = 1000000007;
const ll inf  =	1e9;
const ll linf =	1e18;


void __print(int x)    	        {cerr << x;}
void __print(long x)   	        {cerr << x;}
void __print(float x)  	        {cerr << x;}
void __print(double x) 	        {cerr << x;}
void __print(unsigned x)       	{cerr << x;}
void __print(long long x)      	{cerr << x;}
void __print(long double x)    	{cerr << x;}
void __print(unsigned ll x)    	{cerr << x;}
void __print(unsigned long x)  	{cerr << x;}
void __print(const char *x)    	{cerr << '"' << x << '"';}
void __print(const string &x)  	{cerr << '"' << x << '"';}
void __print(char x)           	{cerr << '\''<< x <<'\'';}
void __print(bool x)           	{cerr <<(x?"true":"false");}

template<typename T, typename V>
	void __print(const pair<T, V> &x)
		{cerr << '{'; __print(x.first);cerr<<',';__print(x.second);cerr<<'}';}
template<typename T>
	void __print(const T &x) 
		{int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
	void _print()
		{cerr << "]\n";}
template <typename T, typename... V>
	void _print(T t, V... v)
		{__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long 

int coinchange(vector<int>& a, int v, int n, vector<vector<int> >& dp)
{
    if (v == 0) return dp[n][v] = 1;
    if (n == 0) return 0;
    if (dp[n][v] != -1) return dp[n][v];

    if (a[n - 1] <= v) 
        return dp[n][v] = (coinchange(a, v - a[n - 1], n, dp) + coinchange(a, v, n - 1, dp))%mod;
    else return dp[n][v] = coinchange(a, v, n - 1, dp);
}
void Solve()
{
	int v;cin>>v;
	vector<int> a = {1, 2, 3, 4, 5, 6, 7 , 8 , 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, 212, 222, 232, 242, 252, 262, 272, 282, 292, 303, 313, 323, 333, 343, 353, 363, 373, 383, 393, 404, 414, 424, 434, 444, 454, 464, 474, 484, 494, 505, 515, 525, 535, 545, 555, 565, 575, 585, 595, 606, 616, 626, 636, 646, 656, 666, 676, 686, 696, 707, 717, 727, 737, 747, 757, 767, 777, 787, 797, 808, 818, 828, 838, 848, 858, 868, 878, 888, 898, 909, 919, 929, 939, 949, 959, 969, 979, 989, 999, 1001, 1111, 1221, 1331, 1441, 1551, 1661, 1771, 1881, 1991, 2002, 2112, 2222, 2332, 2442, 2552, 2662, 2772, 2882, 2992, 3003, 3113, 3223, 3333, 3443, 3553, 3663, 3773, 3883, 3993, 4004, 4114, 4224, 4334, 4444, 4554, 4664, 4774, 4884, 4994, 5005, 5115, 5225, 5335, 5445, 5555, 5665, 5775, 5885, 5995, 6006, 6116, 6226, 6336, 6446, 6556, 6666, 6776, 6886, 6996, 7007, 7117, 7227, 7337, 7447, 7557, 7667, 7777, 7887, 7997, 8008, 8118, 8228, 8338, 8448, 8558, 8668, 8778, 8888, 8998, 9009, 9119, 9229, 9339, 9449, 9559, 9669, 9779, 9889, 9999, 10001, 10101, 10201, 10301, 10401, 10501, 10601, 10701, 10801, 10901, 11011, 11111, 11211, 11311, 11411, 11511, 11611, 11711, 11811, 11911, 12021, 12121, 12221, 12321, 12421, 12521, 12621, 12721, 12821, 12921, 13031, 13131, 13231, 13331, 13431, 13531, 13631, 13731, 13831, 13931, 14041, 14141, 14241, 14341, 14441, 14541, 14641, 14741, 14841, 14941, 15051, 15151, 15251, 15351, 15451, 15551, 15651, 15751, 15851, 15951, 16061, 16161, 16261, 16361, 16461, 16561, 16661, 16761, 16861, 16961, 17071, 17171, 17271, 17371, 17471, 17571, 17671, 17771, 17871, 17971, 18081, 18181, 18281, 18381, 18481, 18581, 18681, 18781, 18881, 18981, 19091, 19191, 19291, 19391, 19491, 19591, 19691, 19791, 19891, 19991, 20002, 20102, 20202, 20302, 20402, 20502, 20602, 20702, 20802, 20902, 21012, 21112, 21212, 21312, 21412, 21512, 21612, 21712, 21812, 21912, 22022, 22122, 22222, 22322, 22422, 22522, 22622, 22722, 22822, 22922, 23032, 23132, 23232, 23332, 23432, 23532, 23632, 23732, 23832, 23932, 24042, 24142, 24242, 24342, 24442, 24542, 24642, 24742, 24842, 24942, 25052, 25152, 25252, 25352, 25452, 25552, 25652, 25752, 25852, 25952, 26062, 26162, 26262, 26362, 26462, 26562, 26662, 26762, 26862, 26962, 27072, 27172, 27272, 27372, 27472, 27572, 27672, 27772, 27872, 27972, 28082, 28182, 28282, 28382, 28482, 28582, 28682, 28782, 28882, 28982, 29092, 29192, 29292, 29392, 29492, 29592, 29692, 29792, 29892, 29992, 30003, 30103, 30203, 30303, 30403, 30503, 30603, 30703, 30803, 30903, 31013, 31113, 31213, 31313, 31413, 31513, 31613, 31713, 31813, 31913, 32023, 32123, 32223, 32323, 32423, 32523, 32623, 32723, 32823, 32923, 33033, 33133, 33233, 33333, 33433, 33533, 33633, 33733, 33833, 33933, 34043, 34143, 34243, 34343, 34443, 34543, 34643, 34743, 34843, 34943, 35053, 35153, 35253, 35353, 35453, 35553, 35653, 35753, 35853, 35953, 36063, 36163, 36263, 36363, 36463, 36563, 36663, 36763, 36863, 36963, 37073, 37173, 37273, 37373, 37473, 37573, 37673, 37773, 37873, 37973, 38083, 38183, 38283, 38383, 38483, 38583, 38683, 38783, 38883, 38983, 39093, 39193, 39293, 39393, 39493, 39593, 39693, 39793, 39893,39993};
	int n = a.size();
	vector<vector<int>> dp(n + 1, vector<int>(v + 1, -1));
	int res = coinchange(a, v, n, dp);
	cout << res %mod<< endl;
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	

	int Testcase = 1; cin>>Testcase;
	while (Testcase--) Solve();
	return 0;
}