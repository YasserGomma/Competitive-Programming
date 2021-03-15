#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
int main()
{
	ll n, ans = 0;
	cin >> n;
	while (n) {
		if (n & 1)ans++;
		n >>= 1;
	}
	cout << ans << endl;
}