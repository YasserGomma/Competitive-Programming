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
int main() {
	int t;
	cin >> t;
	int a, b, c, n;
	unsigned ll fin = 1;
	while (t--) {
		cin >> a >> b >> c >> n;
		priority_queue<ll> pr1;
		priority_queue<ll> pr2;

	pr1.push(1);
		fin = 1;
		ll fn=0;
		for (int i = 2; i <= n; ++i) {
			fn = (1ll * a * pr1.top() + 1ll * b * i + c) % mod;
			fin += fn;
			if (pr1.top() < fn)
				pr2.push(-1*fn);
			else
				pr1.push(fn);

			while (sz(pr1) > sz(pr2) + 1) {
				pr2.push(-1 * pr1.top());
				pr1.pop();
			}

			while (sz(pr2) > sz(pr1)) {
				pr1.push(-1 * pr2.top());
					pr2.pop();
			}
		}

		cout << fin << endl;
	}
}