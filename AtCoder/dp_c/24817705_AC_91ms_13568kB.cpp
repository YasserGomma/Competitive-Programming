#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
typedef long long ll;
#define bay_bay return 0;
#define fori(n) for(int i=0;i<n;++i)
#define for1(n) for(int i=1;i<=n;i+=3)
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
constexpr auto EPS = 1e-9;
#define ff fflush(stdout);
const int mod = 1000000007LL;
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
struct day
{
	ll a, b, c;

};
day days[100009];
ll mem[100009][4];
int n;
ll solve(int idx, int ch)
{
	if (idx == n)
	{
		return 0;
	}
	ll &ret = mem[idx][ch];
	if (~ret)
		return ret;
	ret = LLONG_MIN;
	if (ch != 1)
		ret=max(ret, days[idx].a + solve(idx + 1, 1));
	if (ch != 2)
		ret=max(ret, days[idx].b + solve(idx + 1, 2));
	if (ch != 3)
		ret=max(ret, days[idx].c + solve(idx + 1, 3));
	return ret;

}
int main()
{
	//GOAT();
	cin >> n;
	memset(mem, -1,sizeof mem);
	fori(n)
	{
		cin >> days[i].a >> days[i].b >> days[i].c;
	}
	cout << solve(0, 0) << endl;
	
}