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

int mem[10009][109];
int v[10009];
int n, k;
int fix(int a)
{
	return (a % k + k) % k;
}
bool solve(int idx, int mod)
{
	int &ret = mem[idx][mod];
	if (~ret)return ret;
	if (idx == n)return ret=mod == 0;
	if(solve(idx + 1, fix(mod + v[idx]))||solve(idx + 1, fix(mod - v[idx])))
	return ret = 1;
	return ret = 0;
}
int main()
{
	//GOAT();
	int t;
	cin >> t;
	while (t--)
	{
		memset(mem, -1, sizeof mem);
        cin >> n >> k;
		for (int i = 0; i < n; i++)cin >> v[i];	
		int ans = solve(1, fix(v[0]));
		if(ans)
			cout <<"Divisible"<< endl;
		else
			cout <<"Not divisible" << endl;
	}


}
