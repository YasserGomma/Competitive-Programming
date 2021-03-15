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
	//freopen("output.txt", "w	", stdout);
#else
#endif

}
string s;
int mem[1009][1009];
int solve(int i, int j)
{
	if (i >= j)
		return 0;
	int &ret = mem[i][j];
	if (~ret)return ret;
	ret = solve(i + 1, j - 1) + (s[i] != s[j]);
	ret = min(ret, solve(i + 1, j) + 1);
	ret = min(ret, solve(i , j-1) + 1);
	return ret;
}

int main() {
//	GOAT();
	int t;
	cin >> t; 
	for (int i = 1; i <= t; i++)
	{
		cin >> s;
		clr(mem, -1);
		cout << "Case " << i << ": " << solve(0, int(sz(s)) - 1) << endl;
	}
}

