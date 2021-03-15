#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
typedef long long         ll;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
#define pb					push_back
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
void GOAT()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w	", stdout);
#else
#endif

}
int g[101][101], r, c;
bool valid(int i, int j)
{
	return (i >= 0 && i < r && j >= 0 && j < c);
}
ll mem[105][105];
ll solve(int i, int j)
{
	ll& ret = mem[i][j];
	if (~ret)return ret;
	if (i == r - 1)return g[i][j];
	ll ch1 = -1, ch2 = -1, ch3 = -1;
	if (valid(i + 1, j))
		ch1 = solve(i + 1, j) + g[i][j];
	if (valid(i + 1, j - 1))
		ch2 = solve(i + 1, j - 1) + g[i][j];
	if (valid(i + 1, j + 1))
		ch3 = solve(i + 1, j + 1) + g[i][j];
	return ret = max({ch1, ch2, ch3});
}
ll ans;
void clrall()
{
	clr(mem, -1);
	ans = 0;
}
int main() {
	//GOAT();
	int t; cin >> t;
	while (t--)
	{
		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				cin >> g[i][j];
			}
		clrall();
		for (int i = 0; i < c; i++) {
			ans = max(ans, solve(0, i));
		}
		cout << ans << endl;
	}


}
