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
	vector<int> v(3);

	cin >> v[0] >> v[1] >> v[2];
	sort(all(v));

	string s;
	cin >> s;

	if (s == "ABC") {
		cout << v[0] << " " << v[1] << " " << v[2] << endl;
	}
	if (s == "ACB") {
		cout << v[0] << " " << v[2] << " " << v[1] << endl;
	}
	if (s == "BAC") {
		cout << v[1] << " " << v[0] << " " << v[2] << endl;
	}
	if (s == "BCA") {
		cout << v[1] << " " << v[2] << " " << v[0] << endl;
	}
	if (s == "CAB") {
		cout << v[2] << " " << v[0] << " " << v[1] << endl;
	}
	if (s == "CBA") {
		cout << v[2] << " " << v[1] << " " << v[0] << endl;
	}
}