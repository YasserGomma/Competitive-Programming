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
int mem[5009][5009], s[5009], n, m;
double p[5007];
int solve(int idx, int pre)
{
	if (idx == n)return 0;
	int& ret = mem[idx][pre];
	if (~ret)return ret;
	ret = solve(idx + 1, pre);
	if (s[idx] >= s[pre])
		ret = max(ret, solve(idx + 1, idx) + 1);
	return ret;
}
int main()
{
	GOAT();
	memset(mem, -1, sizeof mem);
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> s[i] >> p[i];
	cout <<n-solve(0, n) << endl;



}