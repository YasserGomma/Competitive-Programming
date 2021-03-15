/*(وَمَا تَوْفِيقِي إِلَّا بِاللَّه) */
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int MOD = (int)1e9 + 7;
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void COME_BACK()
{
	std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}

int adj[102][102];
int main()
{
	COME_BACK();
	int n; cin >> n;
	for (int i = 1; i < 100; i++)
	{
		adj[0][i] = adj[i][0] = 1;
		for (int j = 1; j < i; j++)
		{
			if (n < j)break;
			adj[i][j] = adj[j][i] = 1;
			n -= j;
		}
	}
	cout << 100 << endl;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			cout << adj[i][j];
		cout<< endl;
	}
}