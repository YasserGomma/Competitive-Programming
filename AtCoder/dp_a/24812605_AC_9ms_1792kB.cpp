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
	//freopen("in.txt", "r", stdin);
	//freopen("output.txt", "w	", stdout);
#else
#endif
}
ll arr[100009],dp[100009], n;

int main()
{
	GOAT();
	cin >> n;
	for (int i = 1; i <= n;i++)
		cin >> arr[i];
	arr[0] = arr[1];
	for (int i = 1; i <= n; i++)
	{
		if (i < 2)dp[i] = abs(arr[i]- arr[i - 1]);
		else {
			ll ch1 = dp[i - 1] + abs(arr[i] - arr[i - 1]);
			ll ch2 = dp[i - 2] + abs(arr[i] - arr[i - 2]);
			dp[i] = min(ch1, ch2);
		}

	}
	cout << dp[n] << endl;
}
