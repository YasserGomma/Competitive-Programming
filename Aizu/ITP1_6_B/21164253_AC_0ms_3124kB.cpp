#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int oo = 0x3f3f3f3f, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

ll BS(ll c) {
	ll st = 0, ed = 1e5, ans = -1;
	while (st <= ed) {
		ll md = st + ed >> 1;
		if (md * (md - 1) / 2 >= c) {
			ed = md - 1;
			ans = md;
		}
		else st = md + 1;
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	map<char,int>s, h, C, d;
	while (t--)
	{
		char c;
		int a;
		cin >> c >> a;
		if (c == 'S')
			s[a]++;
		if (c == 'H')
			h[a]++;		
		if (c == 'D')
			d[a]++;		
		if (c == 'C')
			C[a]++;
	}
	for (int i = 1; i <= 13; i++)
	{
		if (s[i]!=1)
		{
			cout << "S " << i << endl;
		}
	}
	for (int i = 1; i <= 13; i++)
	{
		if (h[i]!=1)
		{
			cout << "H " << i << endl;
		}
	}
	for (int i = 1; i <= 13; i++)
	{
		if (C[i]!=1)
		{
			cout << "C " << i << endl;
		}
	}

	for (int i = 1; i <= 13; i++)
	{
		if (d[i]!=1)
		{
			cout << "D " << i << endl;
		}
	}
	


}