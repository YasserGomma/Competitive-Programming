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
int n, x;
vector<int>v;
int mem[101][10005];
int solve(int idx, int rem)
{
	if (idx == n)return 0;
	int& ret = mem[idx][rem];
	if (~ret)return ret;
	ret = 0;
	ret = solve(idx + 1, rem);
	if ((n - idx) * v[idx]<=rem)
		ret = max(ret, solve(idx + 1, rem - ((n - idx) * v[idx])) + 1);
	return ret;
}
int main()
{
	GOAT();
	freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	cin >> n >> x;
	v.resize(n);
	memset(mem, -1, sizeof mem);
	for (int i = 0; i < n; i++)cin >> v[i];
	cout << solve(0, x) << endl;







}