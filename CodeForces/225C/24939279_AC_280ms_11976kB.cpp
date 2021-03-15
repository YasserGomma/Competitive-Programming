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
#define oo 0x3f3f3f3fLL
typedef long long         ll;
const double EPS = (1e-7);
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
	//freopen("output.txt", "w	", stdout);
#else
#endif

}
int n, m, x, y;
int dots[1007];
int mem[1007][1007][3];
int solve(int col, int w, int pre)
{
	if (col == m)return(w < x || w > y) ? oo : 0;
	int& ret = mem[col][w][pre];
	if (~ret)return ret;
	int d = oo, h = oo;
	if (!col || !pre && w < y || pre&1  && w >= x)
		d = n - dots[col] + solve(col + 1, (!pre) ? w + 1 : 1, 0);
	if (!col || pre & 1 && w < y ||!pre && w >= x)
		h = dots[col] + solve(col + 1, pre & 1 ? w + 1 : 1, 1);
	return ret = min(d, h);
}

int main() {
	GOAT();
	clr(mem, -1);
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c; cin >> c;
			if (c == '.')dots[j]++;
		}
	}
	cout << solve(0, 0, 2) << endl;
	//ctime;
}