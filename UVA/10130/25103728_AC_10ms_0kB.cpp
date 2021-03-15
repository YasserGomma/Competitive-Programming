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
int mem[1005][35];
int n, w[1001],p[1001];

int knap(int idx, int wi)
{
	if (idx >= n)return 0;
	int& ret = mem[idx][wi];
	if (~ret)return ret;
	int ch = 0;
	if (wi - w[idx] >= 0)
		ch = knap(idx + 1, wi - w[idx]) + p[idx];
	return ret = max(ch, knap(idx + 1, wi));

}
ll ans;
void clrall()
{
	clr(mem, -1);
	ans = 0;
}
int main() {
	GOAT();
	int t;
	cin >> t;
	while (t--)
	{
		clrall();
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> p[i] >> w[i];
		int fam; cin >> fam;
		while (fam--)
		{
			int wi; cin >> wi;
			ans += knap(0, wi);
		}
		cout << ans << endl;



	}
}