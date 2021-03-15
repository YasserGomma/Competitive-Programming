#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
#define trace(x) cout<<"#trace   "<<x<<endl;
#define bay_bay return 0;
#define fori(n) for(int i=0;i<n;++i)
#define forsz(s )for(int i=0;i<s.size();++i)
#define all(v) ((v).begin()), ((v).end())
#define read(FILE) freopen(FILE,"r",stdin)
#define write(FILE) freopen(FILE,"w",stdout)
#define sz(v) v.size()
#define endl "\n"
void _Sectumsempra_()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
}
int main()
{
	_Sectumsempra_();
	map<string, int>mp;
	int idx = 1;
	for (char i = 'a'; i <= 'z'; i++)
	{
		string x = "";
		x += i;
		mp[x] = idx;
		idx++;
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		for (int j = i + 1; j <= 'z'; j++)
		{

			string x = "";
			x += i;
			x += j;
			mp[x] = idx;
			idx++;
		}
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		for (char j = i + 1; j <= 'z'; j++)
		{
			for (char k =	j + 1; k <= 'z'; k++)
			{


				string x = "";
				x += i;
				x += j;
				x += k;
				mp[x] = idx;
				idx++;
			}
		}
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		for (char j = i + 1; j <= 'z'; j++)
		{
			for (char k = j + 1; k <= 'z'; k++)
			{
				for (char l = k + 1; l <= 'z'; l++)
				{


					string x = "";
					x += i;
					x += j;
					x += k;
					x += l;
					mp[x] = idx;
					idx++;
				}
			}
		}
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		for (char j = i + 1; j <= 'z'; j++)
		{
			for (char k = j + 1; k <= 'z'; k++)
			{
				for (char l = k + 1; l <= 'z'; l++)
				{
					for (char m = l + 1; m <= 'z'; m++)
					{


						string x = "";
						x += i;
						x += j;
						x += k;
						x += l;
						x += m;
						mp[x] = idx;
						idx++;
					}
				}
			}
		}
	}
	string x;
	while (cin >> x)
	{
		if (mp[x] >= 1)
			cout << mp[x] << endl;
		else
			cout << 0 << endl;
	}
}