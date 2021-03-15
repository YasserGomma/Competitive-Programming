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
		string a = "", b = "", nn = "";
		while (n)
		{
			if (n % 2 != 0)
				nn += '1';
			else
				nn += '0';
			n /= 2;

		}
		int cnt = 0;
		for (int i = 0; i < nn.size(); i++)
		{
			if (nn[i] == '1')
			{
				if (cnt % 2 == 0)
					a += '1', b += '0';
				else
					b += '1', a += '0';
				cnt++;
			}
			else
				a += '0', b += '0';

		}
		ll na = 0, nb = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i]=='1')
				na += pow(2, i);
		}
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i]=='1')
				nb += pow(2, i);
		}
		cout << na << " " << nb << endl;
		/*cout << nn<<endl<<a << "   " << b << endl;*/

	

	}

}