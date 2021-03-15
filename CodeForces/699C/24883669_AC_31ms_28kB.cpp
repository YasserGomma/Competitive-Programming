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
int mem[5][105];
int n, arr[105];
int solve(int pre, int idx)
{
	if (idx >= n)return 0;	
	int& ret = mem[pre][idx];
	if (~ret)return ret;
	ret = 1+solve(0, idx + 1) ;
	if (pre != 1 )
		if(arr[idx]== 2 || arr[idx] == 3)
		ret = min(ret, solve(1, idx + 1));
	if (pre != 2)
		if (arr[idx] == 1 || arr[idx] == 3)
			ret = min(ret, solve(2, idx + 1));
	return ret;
}
int main() {
	GOAT();
	cin >> n;
	clr(mem, -1);
	for (int i = 0; i < n; i++)cin >> arr[i];
	cout << solve(0, 0) << endl;
}
