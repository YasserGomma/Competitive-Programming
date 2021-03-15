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
typedef long long         ll;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
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
	//freopen("out.txt", "w	", stdout);
#else
#endif

}
int xi[100005], hi[100005],n;
int mem[100005];
ll solve(int i)
{
	if (i==n-1)return 0;
	int& ret = mem[i];
	if (~ret)return ret;
	if (xi[i] - xi[i - 1] > hi[i])return ret= 1 + solve(i + 1);
	else if (xi[i + 1] - xi[i] > hi[i])
	{
		xi[i] += hi[i];
		return  ret=1 + solve(i + 1);
	}
	return ret = solve(i + 1);
		
}

int main() {
	GOAT();
	clr(mem, -1);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> xi[i] >> hi[i];
	if (n == 1)cout << 1 << endl;
	else
		cout << solve(1) + 2 << endl;



}
