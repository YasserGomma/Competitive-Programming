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
	int t[101], c[101];
	int n, k;
	int mem[101][100009];
	int solve(int idx,int mod)
	{
		if (idx == n)return (mod?-1e9:0);
		int& ret = mem[idx][mod];
		if (~ret)return ret;
		return ret = max(solve(idx + 1, mod), solve(idx + 1, mod+(t[idx]-c[idx]*k))+t[idx]);
	}
	int main() {
		GOAT();
		cin >> n >> k;
		clr(mem, -1);
		for (int i = 0; i < n; i++)cin >> t[i];
		for (int i = 0; i < n; i++)cin >> c[i];
		if (solve(0, 0))cout << solve(0, 0) << endl;
		else cout << -1 << endl;


	

	}