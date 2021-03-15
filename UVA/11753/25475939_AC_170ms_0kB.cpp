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
int n, k;
vector<int>v, re;
map<pair<int, int>, int>mem;
int solve(int i, int j, int rem)
{
	if (rem > k)return 1e9;
	if (i >= j)return rem;
	if (v[i] == v[j])return solve(i + 1, j - 1, rem);
	else return min(solve(i + 1, j, rem + 1), solve(i, j - 1, rem + 1));

}
int main()
{
	GOAT();
	int t; cin >> t;
	int idx = 1;
	while (t--)
	{
		cin >> n >> k;
		v.clear(), re.clear(), v.resize(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		re = v;
		reverse(all(re));
		if (re == v)
		{
			cout << "Case " << idx++ << ": Too easy" << endl;
			continue;
		}
		int ans = solve(0, n - 1, 0);
		if(ans>k)
			cout << "Case " << idx++ << ": Too difficult" << endl;
		else
			cout << "Case " << idx++ << ": "<<ans << endl;


	}

	



}