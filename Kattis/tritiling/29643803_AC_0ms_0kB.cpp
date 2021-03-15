#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define deb(x)   cout << "[" <<#x << "=" << x << "]" << endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int mod = (int)1e9 + 7;
#define clr(v, d)		memset(v, d, sizeof(v))
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void nGu()
{
	std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
}
ll dp[35][8];
ll solve(int n)
{
	dp[0][7] = 1;
	for (int i = 1; i <= n; i++)
	{
		//The number of empty states for this column is the number of full states in the previous column.
		dp[i][0] += dp[i - 1][7];

		dp[i][1] += dp[i - 1][6];

		/* State 2 doesn't contribute to the number of tilings
		 dp[i][2] += dp[i-1][5];*/

		dp[i][3] += dp[i - 1][7];
		dp[i][3] += dp[i - 1][4];

		dp[i][4] += dp[i - 1][3];

		 /*State 5 doesn't contribute to the number of tilings
		 dp[i][5] += dp[i-1][2];*/

		dp[i][6] += dp[i - 1][7];
		dp[i][6] += dp[i - 1][1];

		dp[i][7] += dp[i - 1][3];
		dp[i][7] += dp[i - 1][6];
		dp[i][7] += dp[i - 1][0];

	}
	return dp[n][7];
}
int main()
{
	//nGu();
	int n;
	solve(30);
	while (cin >> n && ~n)
	{
		cout << dp[n][7]<< endl;
	}
}