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
ll arr[100009],dp[100009], n,k;

int main()
{
	//GOAT();
	cin >> n >> k;
	for (int i = 1; i <= n;i++)
		cin >> arr[i];
	memset(dp, -1, sizeof dp);
	dp[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (i + j <= n)
			{
				ll ch = dp[i] + abs(arr[i] - arr[i + j]);
				if (ch < dp[i + j] || dp[i + j] == -1)dp[i + j] = ch;
			}
		}
	}
	cout << dp[n] << endl;
}