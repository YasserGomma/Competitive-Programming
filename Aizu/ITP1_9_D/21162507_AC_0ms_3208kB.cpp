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
	string s;
	cin >> s;
	int t;
	cin >> t;
	while (t--)
	{
		string x;
		cin >> x;
		if (x == "replace")
		{
			int a, b;
			string y;
			cin >> a >> b >> y;
			s.replace(s.begin()+a, s.begin() + b+1, y);
		}
		else if (x == "reverse")
		{
			int a, b;
			
			cin >> a >> b;
			reverse(s.begin() + a, s.begin() + b+1);
		}
		else
		{
			int a, b;
			cin >> a >> b;
			for (int i = a; i <= b; i++)cout << s[i];
			cout << endl;
		}
	}
	

}