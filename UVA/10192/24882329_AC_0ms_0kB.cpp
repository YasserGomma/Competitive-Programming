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
string a,b;
int mem[101][101];
int lcs(int i, int j)
{
	if (i >= sz(a) || j >= sz(b))return 0;
	int& ret = mem[i][j];
	if (~ret)return ret;
	ret = -1;
	if (a[i] == b[j]) {
		// += a[i];
		return  ret = lcs(i + 1, j + 1) + 1;
	}
	int ch1 = lcs(i, j + 1);
	int ch2 = lcs(i + 1, j);
	return ret = max(ch1, ch2);

}
int main() {
	//GOAT();
	int cnt = 1;
	while (getline(cin, a))
	{
		clr(mem, -1);
		if (a[0] == '#')return 0;
		getline(cin, b);
		cout << "Case #" << cnt++ << ": you can visit at most " << lcs(0, 0) << " cities." << endl;
	}
}

