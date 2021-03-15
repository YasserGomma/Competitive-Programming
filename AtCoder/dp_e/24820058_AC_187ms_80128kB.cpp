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
ll v[100007], w[100007], we, n, mxwe;
ll mem[101][100005];
ll knap(int i, ll rem)
{
	if (i > n) {
		return rem == 0 ? 0 : 1e10;
	}
	if (!rem)return 0;
	ll& ret = mem[i][rem];
	if (~ret)return ret;
	ll choice1 = knap(i + 1, rem);
	ll choice2 = 1e10;

	if (rem - v[i] >= 0)
		choice2 = knap(i + 1, rem - v[i]) + w[i];

	return ret = min(choice1, choice2);
}
int main()
{
	//GOAT();
	clr(mem, -1);
	cin >> n >> we;
	for (int i = 0; i < n; i++)
		cin >> w[i] >> v[i];
	//cout << knap(0, we) << endl;
	for (int i = 100001; i >= 0; i--)
	{

		ll mx = i, ans = knap(0, mx);
		if (ans <= we)
		{
			return cout << mx << endl, 0;
		}
	}




}
