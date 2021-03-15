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
	#define oo 0x3f3f3f3fLL
	typedef long long         ll;
	const double EPS = (1e-7);
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
		//freopen("output.txt", "w	", stdout);
	#else
	#endif

	}

void LIS(vector<int> &S, vector<int> &LI)
{
    vector<int> L(S.size());
    int lisCount = 0;
    for (int i = 0; i < S.size(); ++i)
    {
        int pos = lower_bound(L.begin(), L.begin() + lisCount, S[i])
                     - L.begin();
        L[pos] = S[i];
        if (pos == lisCount)
            ++lisCount;
        LI[i] = pos + 1;
    }
}
	int main() {
		GOAT();
		int n;
		while (cin>>n)
		{
			vector<int>v(n);
			for (int i = 0; i < n; i++)cin >> v[i];
			vector<int> LI(n), LD(n);
			LIS(v, LI);
			reverse(all(v));
			LIS(v, LD);
			reverse(all(LD));
			int ans = 0;
			for (int i = 0; i < n; i++)
			{
				ans = max(ans, 2 * min(LI[i], LD[i]) - 1);
			}
			cout << ans << endl;


		}


	

	}