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
	int n, a[2001];
	int mem[2001][2001];
	int mem1[2001][2001];

	int LIS(int i, int prev)
	{
		if (i == n)
			return 0;
		int &ret = mem[i][prev];
		if (~ret)return ret;
		ret=LIS(i + 1, prev);
		if (a[prev] <a[i])
			ret =max(ret, LIS(i + 1, i) + 1);
		return ret;
	}
	int LDS(int i, int prev)
	{
		if (i == n)
			return 0;
		int& ret = mem1[i][prev];
		if (~ret)return ret;
		ret=LDS(i + 1, prev);
		if (a[prev] > a[i])
			ret = max(ret, LDS(i + 1, i) + 1);
		return ret;
	}
	void call()
	{
		clr(mem, -1);
		clr(mem1, -1);
	}
	int main() {
		GOAT();
		int t;
		cin >> t;
		while (t--)
		{
			call();
			cin >> n;
			for (int i = 0; i < n; i++)
				cin >> a[i];
			int ans = 0;
			for (int i = 0; i < n; i++)
			{
				ans = max(ans, LIS(i, i) + LDS(i, i)+1);
			}
			cout<<ans<<endl;

		}


	

	}