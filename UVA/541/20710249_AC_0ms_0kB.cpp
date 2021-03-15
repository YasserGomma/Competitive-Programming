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
	while (cin >> n && n)
	{
		int cnt = 0;
		int arr[101][101];
		for (int i = 0; i < n; i++) {
			
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];

			}
		}
		vector<int>row, col;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				sum += arr[i][j];
			}
			row.push_back(sum);
		}
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				sum += arr[j][i];
			}
			col.push_back(sum);
		}
		int r = 0, c = 0, rx, cx;
		for (int i = 0; i < row.size(); i++)
		{
			if (row[i] & 1)r ++ ,rx=i;
			if (col[i] & 1)c++,cx=i;
		}
		if (!c && !r)
			cout << "OK" << endl;
		else if (c == 1 && r == 1)
			cout << "Change bit (" << rx + 1 << "," << cx + 1 << ")" << endl;
		else
			cout << "Corrupt" << endl;


	

	}

}