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
	#define oo LLONG_MAX
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

	ll n, mem[100007][2],cost[100007];
	string v[100007][2];
	ll solve(int i, int pre)
	{
		if (i == n)return 0;
		ll& ret = mem[i][pre];
		if (~ret)return ret;
		ret = oo;
		if((!i||v[i][0]>=v[i-1][pre])&&solve(i+1,0)!=oo)
			ret = min(ret, solve(i + 1, 0));
		if ((!i || v[i][1] >= v[i - 1][pre])&&solve(i+1,1)!=oo)
			ret = min(ret, solve(i + 1, 1) + cost[i]);

		return ret;
	}
	int main() {
		GOAT();
		clr(mem, -1	);
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> cost[i];
		for (int i = 0; i < n; i++)
		{
			cin >> v[i][0];
			v[i][1] = v[i][0];
			reverse(all(v[i][1]));
		}
		if (solve(0, 0) == oo)cout << -1 << endl;
		else cout << solve(0, 0) << endl;

	

	}