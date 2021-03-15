#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
constexpr auto EPS = 1e-9;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
void GOAT()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
}
void LIS(vector<int>& S, vector<int>& LI)
{
	vector<int> L(S.size());
	int lisCount = 0;
	for (int i = 0; i < S.size(); ++i)
	{
		int pos = lower_bound(L.begin(), L.begin() + lisCount, S[i])- L.begin();
		L[pos] = S[i];
		if (pos == lisCount)
			++lisCount;
		LI[i] = pos + 1;
	}
}
int main()
{
	GOAT();
	int n;
	cin >> n;
	vector<int>v(n),li(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	LIS(v, li);
	
	cout << *max_element(all(li)) << endl;

	


}

