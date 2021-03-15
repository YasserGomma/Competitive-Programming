#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
typedef long long ll;
#define bay_bay return 0;
#define fori(n) for(int i=0;i<n;++i)
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
constexpr auto EPS = 1e-9;
#define ff fflush(stdout);
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
void GOAT()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
}
ll gcd(int a, int b) { return !b ? abs(a) : gcd(b, a % b); }
int n, ar[100005],mem[100005];
vector<int> divisors(int n) {
	vector<int> ret;
	for (int i = 2; 1ll * i * i <= n; ++i) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i != n / i)
				ret.push_back(n / i);
		}
	}
	ret.push_back(n);
	return ret;
}

int main()
{
	GOAT();
	memset(mem, 0, sizeof mem);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> ar[i];
	int mx = 1;
	for (int i = 0; i < n; i++)
	{
		vector<int>v = divisors(ar[i]);
		int ans = 1;
		for (auto it : v)
		{
			ans = max(ans, mem[it]+1);
		}
		mx = max(mx, ans);
		for (auto it : v)mem[it] = ans;
	}
	cout << mx << endl;

}