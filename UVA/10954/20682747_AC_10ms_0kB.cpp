#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 3e5 + 5;
int a[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;

	while (scanf("%d", &n), n) {
		priority_queue<int, vector<int>, greater<int> > q;

		while (n--) {
			int x;
			scanf("%d", &x);
			q.push(x);
		}

		int total = 0, cost = 0;
		while (q.size() > 1) {
			total = q.top();
			q.pop();
			total += q.top();
			q.pop();
			cost += total;
			q.push(total);
		}

		printf("%d\n", cost);
	}

}